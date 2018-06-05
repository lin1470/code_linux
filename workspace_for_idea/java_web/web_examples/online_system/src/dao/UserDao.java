package dao;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;
import java.util.Map;

import com.mysql.jdbc.Connection;
import com.mysql.jdbc.PreparedStatement;

import bean.UserBean;
import daoservice.UserService;
import dbutil.DBUtil;

public class UserDao implements UserService{

	@Override
	public boolean addPerson(UserBean params) {
		// TODO Auto-generated method stub
		Boolean flag=false;
		//增加用户
		Connection conn=(Connection) DBUtil.getConnection();
		String sql ="insert into usertable(username,password,sex,level) values(?,?,?,?)";
		try {
			PreparedStatement ptmt=(PreparedStatement) conn.prepareStatement(sql);
			//连接成功
			//设置要插入的数据
			ptmt.setString(1, params.getUsername());
			ptmt.setString(2, params.getPassword());
			ptmt.setString(3, params.getSex());
			ptmt.setString(4, params.getLevel());
			ptmt.execute();
			flag=true;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return flag;
	}

	@Override
	public boolean deletePersonByID(String params) {
		// TODO Auto-generated method stub
		Boolean flag=false;
		//删除用户
		 Connection conn = (Connection) DBUtil.getConnection();
		 
		    String sql = "delete from usertable where id=?";
		 
		    PreparedStatement ptmt;
			try {
				ptmt = (PreparedStatement) conn.prepareStatement(sql);
				ptmt.setString(1, params);
			    ptmt.execute();
			    flag=true;
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		return flag;
	}

	@Override
	public boolean updatePerson(UserBean params) {
		// TODO Auto-generated method stub
		Boolean flag=false;
		//修改资料
		Connection conn = (Connection) DBUtil.getConnection();
		 
	    String sql = "update usertable set password=?,sex=?,level=? where username=?";
	 
	    PreparedStatement ptmt;
		try {
			ptmt = (PreparedStatement) conn.prepareStatement(sql);
			ptmt.setString(1, params.getPassword());
		    ptmt.setString(2, params.getSex());
		    ptmt.setString(3, params.getLevel());
		    ptmt.execute();
		    flag=true;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return flag;
	}

	@Override
	public UserBean queryPersonById(String selectionArgs) {
		// TODO Auto-generated method stub
		//按用户名查询单个用户记录
		UserBean user=null;
		//连接数据库
		Connection conn=(Connection) DBUtil.getConnection();
		String sql="select * from usertable where username=?";//获取username列的值为？的行
		try {
			PreparedStatement ptmt=(PreparedStatement) conn.prepareStatement(sql);
			ptmt.setString(1, selectionArgs);
			ResultSet rs=ptmt.executeQuery();
			while(rs.next()){
				user=new UserBean();
				user.setUsername(rs.getString("username"));
				user.setPassword(rs.getString("password"));
				user.setSex(rs.getString("sex"));
				user.setLevel(rs.getString("level"));
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//if(user==null)System.out.println("sssssssss");else System.out.println("aaaaaaaa");
		return user;
	}

	@Override
	public List<UserBean> listPersonMaps() {
		// TODO Auto-generated method stub
		return null;
	}
}
