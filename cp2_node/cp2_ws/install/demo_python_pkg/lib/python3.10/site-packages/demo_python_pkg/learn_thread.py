import threading
import requests

class Download:
    def __init__(self):
        pass
        
    def download(self, url, callback_word_content):
        print(f"thread:{threading.get_ident()} start download {url}")
        response = requests.get(url)
        response.encoding = 'utf-8'
        callback_word_content(url, response.text) # 调用回调函数处理下载结果
    
    def start_download(self, url, callback_word_content):
        # self.download(url, callback_word_content) # 同步调用
        thread = threading.Thread(target=self.download, args=(url, callback_word_content))
        thread.start()
    
def word_count(url, result):
    """普通函数，用于回调

    Args:
        url (str): _description_
        result (_type_): _description_
    """
    print(f"{url}: {len(result)} -> {result[:]}")
    
def main():
    download = Download()
    download.start_download('http://127.0.0.1:8000/novel0.txt', word_count)
    download.start_download('http://127.0.0.1:8000/novel1.txt', word_count)
    download.start_download('http://127.0.0.1:8000/novel2.txt', word_count)
    