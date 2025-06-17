#include "iostream"
#include "thread"
#include "chrono"
#include "functional"
#include "cpp-httplib/httplib.h"

class Download
{
private:
    /* data */
public:
    Download(/* args */);
    ~Download();

    void download(const std::string &host, const std::string &path, const std::function<void(const std::string &, const std::string&)> &callback_word_count) {
        std::cout << "thread id: " << std::this_thread::get_id() << std::endl;

        try
        {
            httplib::Client client(host);
            client.set_connection_timeout(5);
            client.set_read_timeout(5);
            
            auto response = client.Get(path);

            if (response)
            {
                std::cout << "status id: " << response->status << std::endl;
                if (response->status == 200)
                {
                    callback_word_count(path,response->body);
                } else {
                    std::cerr << "http请求错误" <<  response->status <<std::endl;
                }
            } else {
                std::cerr << "无法连接到服务器" << std::endl;
            }
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    };

    void start_download(const std::string &host, const std::string &path, const std::function<void(const std::string &, const std::string &)>  &callback_word_count){
        auto download_fun = std::bind(&Download::download, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

        std::thread thread(download_fun, host, path, callback_word_count);

        thread.detach();  // 分离
    };
};

Download::Download(/* args */)
{
}

Download::~Download()
{
}


int main(){
    auto d = Download();
    auto word_count = [](const std::string &path, const std::string &result) -> void {
        std::cout << "finish download " << path << result.length() << "=>" <<result.substr(0) << std::endl;
    };

    d.start_download("127.0.0.1:8000", "/novel0.txt", word_count);
    d.start_download("127.0.0.1:8000", "/novel1.txt", word_count);
    d.start_download("127.0.0.1:8000", "/novel2.txt", word_count);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000*10));
}