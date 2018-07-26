package dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;




import bean.ChengjiBean;
import daoservice.ChengjiService;
import dbutil.DBUtil;

public class ChengJiDao implements ChengjiService{

	@Override
	public boolean addChengji(ChengjiBean params) {
		// TODO Auto-generated method stub
		Boolean flag=false;
		//增加用户
		Connection conn=(Connection) DBUtil.getConnection();
		String sql ="insert into chengjitable(username,level,score) values(?,?,?)";
		try {
			PreparedStatement ptmt=(PreparedStatement) conn.prepareStatement(sql);
			//连接成功
			//设置要插入的数据
			ptmt.setString(1, params.getUsername());
			ptmt.setString(2, params.getLevel());
			ptmt.setFloat(3, params.getScore());
			ptmt.execute();
			flag=true;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return flag;
	}
	
	public List<ChengjiBean> queryChengjiByUsername(String username){
		List<ChengjiBean> chengjilist= new ArrayList<ChengjiBean>();
		Connection conn=DBUtil.getConnection();
		StringBuilder sql=new StringBuilder();
		sql.append("select * from chengjitable where username=?");//level,fenzhi,tigan,xx1,xx2,xx3,xx4,answer
		try {
			PreparedStatement ptmt=conn.prepareStatement(sql.toString());
			ptmt.setString(1, username);//如果有形式参数，一定要用这个设置进来
			ResultSet rs=ptmt.executeQuery();
			ChengjiBean chengji=null;
			while(rs.next()){
				chengji=new ChengjiBean();
				chengji.setUsername(rs.getString("username"));
				chengji.setLevel(rs.getString("level"));
				chengji.setScore(rs.getFloat("score"));
				chengjilist.add(chengji);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return chengjilist;
		
	}

}
