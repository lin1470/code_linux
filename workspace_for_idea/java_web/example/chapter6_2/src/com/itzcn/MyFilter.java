package com.itzcn;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import java.io.IOException;

/**
 * Created by bruce on 5/11/17.
 */
@WebFilter(filterName = "MyFilter",urlPatterns = "/MyFilter")
public class MyFilter implements Filter {
    public void destroy() {
        System.out.println("MyFilter is ended\n");
    }

    public void doFilter(ServletRequest req, ServletResponse resp, FilterChain chain) throws ServletException, IOException {
        chain.doFilter(req, resp);

    }

    public void init(FilterConfig config) throws ServletException {
        System.out.println("MyFilter is initialized\n");

    }

}
