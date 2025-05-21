1 使用命令行生成
   ssh-keygen -m PEM -t rsa -f HDPDFIS.rsa (HDPDFIS.ras只是举例使用的项目名称，可以使用任何文件名)
   输入[密码]后会生成两文件
   HDPDFIS.ras
   HDPDFIS.ras.pub

2 生成工程所需要的public_key.h文件，供使用加密项目使用 (详见:lccgen.exe project initialize --help)
   (A) cmd在D:\SourceCode\HDS\licensecc\projects目录下
       HDPDFIS\licensecc\bin\lccgen.exe project initialize -n HDPS  -t D:\SourceCode\HDS\licensecc\projects\HDPDFIS\licensecc\bin\templates   
   (B)
      lccgen.exe project initialize -n HDNLRP --primary-key HDPDFIS.ras --public-key HDPDFIS.ras.pub -p HDNLRP -t D:\SourceCode\HDS\licensecc\projects\HDPDFIS\licensecc\bin\templates
   注意：(1) -t 后面的模板一定要指定
         (2) primary-key --- HDPDFIS.ras （可不指定）
		     public-key  --- HDPDFIS.ras.pub（可不指定）
			 licensecc_static.lib --- public_key.h
			 其中工程所需信赖关系：licensecc_static.lib -> os.lib  -> public_key.h
			 [licensecc_static工程中包函了os中的许多obj文件，其中也就是os.lib]
         (3)在(2)的基础上修改了public_key中的定义位置，直接在所需的工程中添加全局g_public_key
		    // 这是HDNLRP工程的public_key,不同的工程添加内容不同，根据生成的public_key.h中的定义copy过来即可。
		     #if !_DEBUG
				#define PRODUCT_NAME HDNLRP
				unsigned char g_public_key[] = {
					48,	 129, 137, 2,	129, 129, 0,   175, 97,	 222, 57,  228, 187, 186, 6,   247, 52,	 170, 127, 92,
					19,	 72,  63,  117, 129, 142, 239, 112, 77,	 55,  215, 174, 1,	 195, 243, 184, 158, 143, 78,  38,
					106, 200, 219, 156, 144, 233, 135, 164, 91,	 68,  144, 118, 96,	 46,  163, 95,	27,	 244, 43,  133,
					19,	 11,  199, 219, 93,	 196, 234, 49,	64,	 184, 25,  21,	40,	 141, 143, 227, 100, 245, 85,  51,
					198, 130, 213, 231, 166, 3,	  192, 166, 109, 184, 184, 203, 245, 53,  81,  2,	33,	 240, 246, 183,
					94,	 135, 123, 23,	106, 128, 122, 152, 91,	 122, 40,  36,	97,	 51,  40,  250, 119, 21,  15,  118,
					34,	 19,  108, 157, 127, 180, 76,  211, 219, 61,  232, 213, 83,	 16,  121, 2,	3,	 1,	  0,   1
				};
			#endif

3 需要datatypes.h licensecc.h licensecc_properties.h
  这里我们的本地工程release版本都指向
  [include目录]
  ../../../licensecc\projects\HDPDFIS\licensecc\include\licensecc/DEFAULT
  ../../../licensecc\projects\HDPDFIS\licensecc\include\licensecc
  [链接目录]
  ../../../licensecc\projects\HDPDFIS\licensecc\licensecc\DEFAULT\licensecc_static.lib