package com.servlet;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

import com.student.Student;

/**
 * Created by bruce on 5/23/17.
 */
@WebServlet(name = "registerServlet",urlPatterns="/registerServlet")
public class registerServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setContentType("text/html");
        //String name =new String(request.getParameter("name").getBytes("ISO8859-1"),"UTF-8");
        String name=request.getParameter("name");
       // System.out.println(name);
        String account = request.getParameter("account");
        String password = request.getParameter("password");
        String idNumber = request.getParameter("idNumber");
        String eMail = request.getParameter("eMail");
        PrintWriter out = response.getWriter();

        Student student = new Student(account, password, name, idNumber, eMail);
        ServletContext application = getServletContext();
        List<Student> lt = (List<Student>) application.getAttribute("students");
        if (lt == null) {
            lt = new ArrayList<Student>();
        }
        lt.add(student);
        application.setAttribute("students", lt);//把这个注册的信息都放在这个大的范围的服务器应用里面的。
        response.sendRedirect("register_successfully.html");

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request,response);
    }
}
