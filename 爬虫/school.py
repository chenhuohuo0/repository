import requests
#发送到地址
url='https://www.ahut.edu.cn/'
headers={'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 Edg/114.0.1823.67'
         }
#发送请求
resp=requests.get(url,headers)
#转换格式
resp.encoding='utf-8'
#写入
with open('school.html','w',encoding='utf-8') as f:
    f.write(resp.text)