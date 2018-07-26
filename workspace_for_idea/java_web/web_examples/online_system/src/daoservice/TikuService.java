package daoservice;

import java.util.List;

import bean.TikuBean;

public interface TikuService {
	public List<TikuBean> listTiMuByLevel(String level);//根据题目等级列出题库的所有题
}
