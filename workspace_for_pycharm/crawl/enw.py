#!/usr/bin/python 
# coding: UTF-8

import HTMLParser
import urlparse
import urllib
import urllib2
import cookielib
import string
import re

# 登录的主页面
hosturl = 'https://sso.stu.edu.cn/login'#
# post数据接收和处理的页面（我们要向这个页面发送我们构造的Post数据）
posturl = 'https://sso.stu.edu.cn/login?service=https%3A%2F%2Fmy.stu.edu.cn%2Fdiscussion%2Fmy-courses'

# 设置一个cookie处理器，它负责从服务器下载cookie到本地，并且在发送请求时带上本地的cookie
cj = cookielib.LWPCookieJar()
cookie_support = urllib2.HTTPCookieProcessor(cj)
opener = urllib2.build_opener(cookie_support, urllib2.HTTPHandler)
urllib2.install_opener(opener)

# 打开登录主页面（他的目的是从页面下载cookie，这样我们在再送post数据时就有cookie了，否则发送不成功）
h = urllib2.urlopen(hosturl)

# 构造header，一般header至少要包含一下两项。这两项是从抓到的包里分析得出的。
headers = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36',
           'Referer': 'https://sso.stu.edu.cn/login?service=https%3A%2F%2Fmy.stu.edu.cn%2Fdiscussion%2Fmy-courses'}
# 构造Post数据，他也是从抓大的包里分析得出的。
postData = {"lt":'LT-182565-BngRPsg2pofwul009Tscun4ejkZy0a',
"username":"15zlli2",
"password":"QERtu1014",
"execution":"e1s1",
"_eventId":"submit"
}

# 需要给Post数据编码
postData = urllib.urlencode(postData)

# 通过urllib2提供的request方法来向指定Url发送我们构造的数据，并完成登录过程
request = urllib2.Request(posturl, postData, headers)
print (request)
response = urllib2.urlopen(request)
text = response.read()
print (text)