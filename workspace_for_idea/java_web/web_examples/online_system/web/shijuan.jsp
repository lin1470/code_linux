<%@page import="bean.UserBean"%>
<%@page import="java.util.Iterator"%>
<%@page import="java.util.ArrayList"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
    <%@ page import="bean.TikuBean" %>
    <%@ page import="dao.TikuDao" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>试卷</title>
<link rel="stylesheet" type="text/css" href="shijuancss.css" />
<script type="text/javascript">  

//设置截止时间  
var endDate = new Date();  
var end = endDate.getTime()+610000; //设置时间差为1分钟
        function countTime() {  
            //获取当前时间  
            var date = new Date();  
            var now = date.getTime();  
            //时间差  
            var leftTime = end-now;  
            //定义变量 d,h,m,s保存倒计时的时间  
            var h,m,s;  
            if (leftTime>=0) {   
                h = Math.floor(leftTime/1000/60/60%24);  
                m = Math.floor(leftTime/1000/60%60);  
                s = Math.floor(leftTime/1000%60);                     
            }
            
            //时间到后的事件
            if(h==0&&m==0&&s==0){
            	document.getElementById("_s").innerHTML = s+"秒"; 
            	alert("时间到！");
            	var form=document.getElementsByName("form1")[0];//后面的0表示从所有name为form1的表单中取第一个
            	form.submit();
            }else{
                        
            //将倒计时赋值到div中  
            document.getElementById("_h").innerHTML = h+"时";  
            document.getElementById("_m").innerHTML = m+"分";  
            document.getElementById("_s").innerHTML = s+"秒"; 
            
            //递归每秒调用countTime方法，显示动态时间效果  
            setTimeout(countTime,1000);  }
  
        }  
    </script>
</head>
<body onload="countTime()">
<div id="jishiqi">
<div><p>本页倒计时：</p><hr /></div>
<div id="shizhong">
        <span id="_h">00</span>  
        <span id="_m">00</span>  
        <span id="_s">00</span>  
</div>
</div>
<div id="main">
<div id="topim"></div>
<div id="biaoti">
<h2 align="center">考试</h2>
</div>
<hr />
<div id="timu" >
<form action="GaiJuanServer" method="post" name="form1">
<%

application.setAttribute("sellevel", request.getAttribute("selectlevel"));

int tihao=1;
List<TikuBean> timuList=(List<TikuBean>)request.getAttribute("list");
int length=timuList.size();
int tt=0;int sjscore=0;
ArrayList<String>  answer=new ArrayList<String>();
int[] fenzhi=new int[length];

for(TikuBean timu:timuList){
	answer.add(timu.getAnswer());
	fenzhi[tt]=timu.getFenZhi();
	tt++;
	if(sjscore<100){
		out.print(tihao+"."+"("+timu.getFenZhi()+"分) "+timu.getTiGan());%>
<br>		
<input  class="tm" type="radio" name="di<%=tihao %>ti" value="A" /><%out.print(timu.getXx1());%> 
<br>               
<input  class="tm" type="radio" name="di<%=tihao %>ti" value="B" /><%out.print(timu.getXx2());%>  
<br>
<input  class="tm" type="radio" name="di<%=tihao %>ti" value="C"  /><%out.print(timu.getXx3());%> 
<br>               
<input   class="tm" type="radio" name="di<%=tihao %>ti" value="D" /><%out.print(timu.getXx4());%>
<br>
<%	tihao++;

sjscore+=timu.getFenZhi();
}else break;
	
}
session.setAttribute("tishu", tihao-1);
session.setAttribute("answer", answer);
Iterator it=answer.iterator();
while(it.hasNext())
	System.out.println(it.next());
session.setAttribute("fenzhi", fenzhi);
%>
<input class="tijiao" type="submit" value="提交"/>
</form>
</div>
</div>
</body>
</html>