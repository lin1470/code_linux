package bean;

public class ChengjiBean {
	private String username;
	 private String level;
	 private float score;
	 
	 public void setUsername(String user){
		 this.username=user;
	 }
	 public void setLevel(String level){
		 this.level=level;
	 }
	 public void setScore(float score){
		 this.score=score;
	 }
	 public String getUsername(){
		 return username;
	 }
	 public String getLevel(){
		 return level;
	 }
	 public float getScore(){
		 return score;
	 }
}
