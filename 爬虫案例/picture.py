import requests
from lxml import etree
import os
from os.path import exists
#发送到地址
for i in range(2,5):
    url=f'https://pic.netbian.com/4kmeinv/index_{i}.html'.format(i)
    headers={'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 Edg/114.0.1823.67'
             }
    resp=requests.get(url,headers).text
    if not exists('./图片'):
        os.mkdir('./图片')
    #数据解析
    list=etree.HTML(resp).xpath('//ul[@class="clearfix"]/li')#把所有的li标签提取出来
    for j in list:#遍历所有的li标签
        name=j.xpath('./a/img/@alt')[0]
        name=name.encode('ISO-8859-1').decode('gbk')

        address=j.xpath('./a/img/@src')[0]
        address='https://pic.netbian.com'+address
        response=requests.get(address,headers).content#再次对更新的地址发送请求并把当前图保存下来
        name='图片/'+name+'.jpg'
        with open(name,'wb')as f:
            f.write(response)
            print(name+'已下载')
        #写入

