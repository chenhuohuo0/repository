import requests
from lxml import etree
import os
url='https://www.93xscc.com/douluodalu5/2700508.html'
headers={
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36'
}
k=1
while True:
    resp=requests.get(url,headers)
    resp.encoding='utf-8'
    resp=resp.text

    response=etree.HTML(resp)
    name = response.xpath('//div[@class="m-title col-md-12"]/h1/text()')[0]
    with open('novel.txt','a+',encoding='utf-8')as f:
        f.write(name+'\n\n')
    content=response.xpath('//div[@id="content"]/p')
    for i in content:
        with open('novel.txt','a+',encoding='utf-8')as f:
            f.write(i.text+'\n')
    print('第'+str(k)+'章已下载')
    k+=1
    address=response.xpath('/html/body/div/div/div[7]/a[3]/@href')[0]
    url='https://www.93xscc.com'+address

