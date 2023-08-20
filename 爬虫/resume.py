import requests
from lxml import etree
import os
from os.path import exists

url='https://sc.chinaz.com/jianli/free.html'
headers={'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 Edg/114.0.1823.67'
         }
resp=requests.get(url,headers).text

if not exists('./resume'):
    os.mkdir('./resume')
list=etree.HTML(resp).xpath('//*[@id="container"]/div')
for i in list:
    name = i.xpath('./a/img/@alt')[0]
    name = name.encode('ISO-8859-1').decode('utf-8')
    names = 'resume/' + name + '.rar'

    address=i.xpath('./a/@href')[0]
    resp1=requests.get(address,headers).text
    response=etree.HTML(resp1).xpath('//*[@id="down"]/div[2]/ul/li[5]/a/@href')[0]
    resp2=requests.get(response,headers).content
    with open(names,'wb')as f:
        f.write(resp2)
        print(name+'已下载')
#只爬了一页
