package servers;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import sun.rmi.server.Dispatcher;
import dao.UserDao;
import bean.UserBean;

/**
 * Servlet implementation class ZhuceServer
 */
@WebServlet("/ZhuceServer")
public class ZhuceServer extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ZhuceServer() {
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
		//验证用户注册信息是否正确
		RequestDispatcher dispatcher = null;//指定跳转页面
		String zcusername=request.getParameter("zcusername");
		String zcpassword=request.getParameter("zcpassword");
		String message;
		if(zcusername==null||zcusername==""){
			message="用户名不能为空！";
			request.setAttribute("mes", message);
			dispatcher=request.getRequestDispatcher("tiaozhuan2.jsp");
		}else if (zcpassword==null||zcpassword=="") {
			message="密码不能为空！";
			request.setAttribute("mes", message);
			dispatcher=request.getRequestDispatcher("tiaozhuan2.jsp");
		}else{
		UserDao dao=new UserDao();
		if(dao.queryPersonById(zcusername)==null){//判断用户是否已被注册
	UserBean user=new UserBean();	
	user.setUsername(zcusername);
	user.setPassword(zcpassword);
	user.setSex(request.getParameter("sex"));
	user.setLevel(request.getParameter("level"));
	dao.addPerson(user);//插入到数据库
	request.setAttribute("mes", "注册成功！");//返回信息
	dispatcher=request.getRequestDispatcher("tiaozhuan.jsp");
	System.out.println("chenggong!");
		}
		else {
			request.setAttribute("mes", "该用户已存在！");
			dispatcher=request.getRequestDispatcher("tiaozhuan2.jsp");
			System.out.println("shibai");
		}
		}
		dispatcher.forward(request, response);
	}
}
