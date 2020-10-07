
import ftplib

def ftp_download():
    file_remote = 'ftp_upload.jpg'
    file_local = '/home/pi/Desktop/Camera-Rasp-Arduino-sensors/test_download.jpg'
    bufsize = 1024
    fp = open(file_local, 'wb')
    f.retrbinary('RETR ' + file_remote, fp.write, bufsize)
    fp.close()
    
def ftp_upload():
    file_remote = 'test_upload.jpg'
    file_local = '/home/pi/Desktop/Camera-Rasp-Arduino-sensors/test_upload.jpg'
    bufsize = 1024
    fp = open(file_local, 'rb')
    f.storbinary('STOR ' + file_remote, fp, bufsize)
    fp.close()

    
if __name__ == '__main__':
    host = 'www.aiforu.com'
    username = 'admin_camera'
    password = 'QcZ8M9aDga'
        
        
    f = ftplib.FTP(host)
    f.login(username, password)
        
        
    pwd_path = f.pwd()
    print("FTP当前路径：", pwd_path)
        
        
        
ftp_download()
ftp_upload()
f.quit()
        