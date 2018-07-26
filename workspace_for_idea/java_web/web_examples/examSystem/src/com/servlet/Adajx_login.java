package com.servlet;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Created by bruce on 5/25/17.
 */
@WebServlet(name = "Adajx_login",urlPatterns="/Adajx_login")
public class Adajx_login extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setContentType("text/html;charset=utf-8");
        String account=request.getParameter("account");
        String password=request.getParameter("password");
        PrintWriter out=response.getWriter();
        if(account.equals("123")&&password.equals("123")){
            out.println("登录成功了！");
        }
        else{
            out.println("没有该用户！");
        }

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request,response);
    }
}
