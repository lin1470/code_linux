package com.itzcn.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.itzcn.bean.User;
@WebServlet("/AddServlet")
public class AddServlet extends HttpServlet {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * Constructor of the object.
	 */
	public AddServlet() {
		super();
	}

	/**
	 * Destruction of the servlet. <br>
	 */
	public void destroy() {
		super.destroy(); // Just puts "destroy" string in log
		// Put your code here
	}

	/**
	 * The doGet method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to get.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		doPost(request, response);
	}

	/**
	 * The doPost method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to post.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		request.setCharacterEncoding("utf-8");//����request�ı����ʽ
		response.setContentType("text/html");
		String name = request.getParameter("name");//��ȡ�û���
		String ageStr = request.getParameter("age");//��ȡ�û�����
		String sex = request.getParameter("sex");//��ȡ�Ա�
		String address = request.getParameter("address");//��ȡ��ַ
		String regex = "^\\+?[1-9][0-9]*$";//������ʽ
		int age = 0;
		if (ageStr.matches(regex)) {
			age = Integer.parseInt(ageStr);
		}
		
		User user = new User();//ʵ����User
		user.setName(name);
		user.setAddress(address);
		user.setAge(age);
		user.setSex(sex);
		ServletContext application = getServletContext();//��ȡServletContext����
		List<User> lt = (List<User>) application.getAttribute("users");
		if (lt == null) {
			lt = new ArrayList<User>();
		}
		lt.add(user);
		application.setAttribute("users", lt);
		request.getRequestDispatcher("/list.jsp").forward(request, response);

	}

	/**
	 * Initialization of the servlet. <br>
	 *
	 * @throws ServletException if an error occurs
	 */
	public void init() throws ServletException {
		// Put your code here
	}

}
