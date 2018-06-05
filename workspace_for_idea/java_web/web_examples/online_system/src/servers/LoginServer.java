package servers;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import bean.UserBean;
import dao.UserDao;

/**
 * Servlet implementation class LoginServer
 */
@WebServlet("/LoginServer")
public class LoginServer extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public LoginServer() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doPost(request,response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		//验证登录信息是否正确
		RequestDispatcher dispatcher;//指定跳转页面
		UserDao dao=new UserDao();
		UserBean user=new UserBean();
		user=dao.queryPersonById(request.getParameter("dlusername"));
		if(user==null){
			request.setAttribute("mes", "用户名错误！");
			dispatcher=request.getRequestDispatcher("tiaozhuan.jsp");
		}else if(!(user.getPassword().equals(request.getParameter("dlpassword")))){
			
				request.setAttribute("mes", "密码错误！");
				dispatcher=request.getRequestDispatcher("tiaozhuan.jsp");
			
		}else{
			request.setAttribute("lguser", user);
			dispatcher=request.getRequestDispatcher("test.jsp");
		}
		dispatcher.forward(request, response);
	}

}
