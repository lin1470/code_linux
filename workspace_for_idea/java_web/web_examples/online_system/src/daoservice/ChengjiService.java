package daoservice;

import java.util.List;

import bean.ChengjiBean;

public interface ChengjiService {
	public boolean addChengji(ChengjiBean params);//更新最高成绩
	public List<ChengjiBean> queryChengjiByUsername(String username);//查询当前用户所有成绩
}
