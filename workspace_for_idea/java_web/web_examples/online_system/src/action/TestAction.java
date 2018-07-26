package action;

import java.util.List;

import dao.ChengJiDao;
import dao.TikuDao;
import dao.UserDao;
import bean.ChengjiBean;
import bean.TikuBean;
import bean.UserBean;

public class TestAction {
	public static  void addUser(){
		UserBean user=new UserBean();
		UserDao dao=new UserDao();
		user.setUsername("abcd");
		user.setPassword("111");
		user.setSex("male");
		user.setLevel("chuji");
		dao.addPerson(user);
	}
	public static void addChengji(){
		ChengjiBean cj=new ChengjiBean();
		ChengJiDao cjdao=new ChengJiDao();
		cj.setUsername("guanyu");
		cj.setLevel("gaoji");
		cj.setScore(70);;
		cjdao.addChengji(cj);
	}
//	public UserBean get(String username){
//		UserDao dao=new UserDao();
//		return dao.queryPersonById(username);
//	}
//	public List<TikuBean> timuList(String level){
//		TikuDao dao=new TikuDao();
//		return dao.listTiMuByLevel(level);
//		
//	}
	public static void  main(String[] args) {
		//addUser();//java中 静态方法不可以直接调用非静态方法和成员,所以addUser要变成静态方法
		UserDao userDao=new UserDao();
		UserBean user1=userDao.queryPersonById("a");
		System.out.println(user1.getUsername()+user1.getSex()+user1.getLevel());
		TikuDao dao=new TikuDao();
		List<TikuBean> timuList=dao.listTiMuByLevel("zhongji");
		for(TikuBean timu:timuList){
			System.out.println(timu.getTiLevel()+" "+timu.getFenZhi()+" "+timu.getTiGan()+" "+timu.getXx1());
		}
		//addChengji();
		float t=0;
		ChengJiDao cjdao=new ChengJiDao();
		List<ChengjiBean> cjlist=cjdao.queryChengjiByUsername("guanyu");
		for(ChengjiBean cjb:cjlist){
			if(cjb.getLevel().equals("chuji")&&(cjb.getScore()>t)){
				t=cjb.getScore();
			System.out.println(cjb.getUsername()+cjb.getLevel()+t);
			}
		}
	}

}
