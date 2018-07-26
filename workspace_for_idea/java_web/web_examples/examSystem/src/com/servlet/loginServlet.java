package com.servlet;

import com.student.Student;

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

/**
 * Created by bruce on 5/23/17.
 */
@WebServlet(name = "loginServlet",urlPatterns="/loginServlet")
public class loginServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setContentType("text/html;charset=utf-8");
        String account=request.getParameter("account");
        String password=request.getParameter("password");
        ServletContext application=getServletContext();
        PrintWriter out=response.getWriter();
        List<Student> lt = (List<Student>) application.getAttribute("students");
        if(lt==null){
            Student student=new Student("123","123","123","123","123");
            lt=new ArrayList<Student>();
            lt.add(student);
            application.setAttribute("students", lt);
            out.println("大哥啊，请你先注册吧！");
            return ;
        }
       // out.println("大哥啊，你是哪里错的了");
        int found=0;
        for(Student student:lt){
            if(student.getAccount().equals(account)&&student.getPassword().equals(password))
            {

                found=1;
                break;
            }
        }
        if(found==1){
            out.println("登录成功！");
            //response.sendRedirect("begin_exam.jsp");
        }
        else
        {
            out.println("密码或者账号错误！");
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request,response);
    }
}
