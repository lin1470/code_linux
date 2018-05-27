package com.servlet;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.bean.User;

/**
 * Servlet implementation class AddServlet
 */
@WebServlet("/AddServlet")
public class AddServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AddServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		//response.getWriter().append("Served at: ").append(request.getContextPath());
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html");
		String name=request.getParameter("name");
		String ageStr=request.getParameter("age");
		String sex=request.getParameter("sex");
		String address=request.getParameter("address");
		String regex="^\\+?[1-9][0-9]*$";
		int age=0;
		if(ageStr.matches(regex)){
			age=Integer.parseInt(ageStr);
		}
		User user=new User();
		user.setName(name);
		user.setAddress(address);
		user.setAge(age);
		user.setSex(sex);
		ServletContext application=this.getServletContext();
		List<User> lt=(List<User>) application.getAttribute("users");
		if(lt==null)
			lt=new ArrayList<User>();
		lt.add(user);
		application.setAttribute("users", lt);
		request.getRequestDispatcher("/list.jsp").forward(request,response);
		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
