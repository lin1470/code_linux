package com.itzcn.servlet;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
@WebServlet("/servlet/LoginServlet")
public class LoginServlet extends HttpServlet {
	private ArrayList<String> users = null;
	private ServletContext context  =null;
	

	/**
	 * Constructor of the object.
	 */
	public LoginServlet() {
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

		request.setCharacterEncoding("utf-8");
		//����Ŀ������һ��ʱ����������Ŀֻ����һ�Σ�Ψһ��
        context = this.getServletContext(); 
        boolean flag = false;
        String url="../login.jsp";
        
        String username=request.getParameter("username");
      
        
        //��ȡ�û��б�,��һ�λ�ȡʱ��Ϊ��   
        users =(ArrayList<String>)context.getAttribute("users");
        //��һ���û���¼ʱ
        if(users.isEmpty()){
            users = new ArrayList<String>();     
            users.add(username);   
            context.setAttribute("users", users);   //����һ���û������ֱ��浽ServletContext������   
            System.out.println("--------��һ���û���¼------");
            
        //�ǵ�һ���û���¼   
        }else{
            for(String user : users){
                //������û��Ѿ���¼,����error.jsp�������ٵ�¼
                if(username.equals(user)){
                    url = "../error.jsp";   
                    System.out.println("--------�ظ���¼------");
                    flag = true;
                    break;   
                }
            }
            if (!flag) {
                //������û�û��¼,�ͽ����û������ֱ��浽ServletContext������
                System.out.println("--------���ظ���¼------");
                users.add(username); 
                
			} 

        }
        for (String string : users) {
			System.out.println("==========" + string+"==========");
		}

        
        response.sendRedirect(url); 
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
