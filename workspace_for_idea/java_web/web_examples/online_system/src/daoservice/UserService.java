package daoservice;

import java.util.List;
import java.util.Map;

import bean.UserBean;

public interface UserService {
	public boolean addPerson(UserBean params);//增加用户
    public boolean deletePersonByID(String params);//删除用户
    public boolean updatePerson(UserBean params);//修改用户信息
    public UserBean queryPersonById(String selectionArgs);//查询单个记录
    public List<UserBean> listPersonMaps();//查询所有记录
}
