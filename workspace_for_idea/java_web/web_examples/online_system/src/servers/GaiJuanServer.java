package servers;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Iterator;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import bean.UserBean;

/**
 * Servlet implementation class GaiJuanServer
 */
@WebServlet("/GaiJuanServer")
public class GaiJuanServer extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public GaiJuanServer() {
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
		//用于改卷和显示成绩
		int tihao=1;
		String stishu=request.getSession().getAttribute("tishu").toString();
		int tishu=Integer.parseInt(stishu);//获取题数
		@SuppressWarnings("unchecked")
		ArrayList<String> ckanswer=(ArrayList<String>) request.getSession().getAttribute("answer");
		Iterator<String> it = ckanswer.iterator();//获取标准答案数组
		int[] fenzhi=(int[])request.getSession().getAttribute("fenzhi");//获取每道题的分值
		String uanswer[]=new String[tishu];//获取用户填写的答案
        int score=0;	
		response.setContentType("text/html;charset=GBK");//解决输出中文乱码问题
		PrintWriter out=response.getWriter();		
		for (int i = 0; i < tishu; i++) {
			if(request.getParameter("di"+tihao+"ti")!=null){
			uanswer[i]=request.getParameter("di"+tihao+"ti").toString();
			//System.out.println(answer[i]);
			//System.out.println(ckanswer.get(i));
//			while(it.hasNext())
//				System.out.println(it.next());
			if(uanswer[i].equals(it.next())){
				score+=fenzhi[i];
			}
			}
		tihao++;
		}
//		out.print("<body >");
//		out.print("<div style='border:1px dashed red; padding:60px 0; margin:30px;text-align: center'>");
//		out.println("<div><h3>您本次考试的成绩为："+"<span style='color:red'>"+score+"</span>"+"分</h3></div>");
//		out.print("</div>");
//		out.print("<a style='margin-left: 700px' href='xinxi.jsp'>返回</a>");
//		out.print("&nbsp;&nbsp;&nbsp;&nbsp;<a  href='login.jsp'>注销</a>");
//		out.print("</body>");
		request.setAttribute("score", score);
		RequestDispatcher dispatcher=request.getRequestDispatcher("chengji.jsp");
		dispatcher.forward(request, response);
	}

}
