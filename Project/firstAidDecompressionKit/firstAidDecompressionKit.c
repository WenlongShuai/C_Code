
/* 描述部分 */
/*
------------------------------------------------------
A、HEADLIN 部分
1、喇叭
	识别声音转换成文字在 HEADLIN栏 显示（标题）
	
2、打气筒
	打气筒按压的次数越多，HEADLIN栏的内容越膨胀
	
------------------------------------------------------

B、TEXT
3、高光笔
  	识别TEXT栏的文字，在大屏幕报纸上显示。
  	大屏幕报纸上被高光笔划过的区域的文字 加租+灰色高亮。

4、吹风机
	吹风机被按下，大屏幕报纸所在位置未被高光笔划过的文字，将被朝吹风机出风口位置吹散。
	
5、六个按钮
	总共6个按钮，每个按钮对应一个标签。
	标签内容可以通过左右三角形切换。
	按下按钮的标签内容将在右侧小屏幕显示。

------------------------------------------------------

C、IMAGE
6、IMAGE+手指
	选择IMAGE栏的照片，点亮选择后的照片。

7、操纵杆
	识别操纵杆移动的方向，随着操纵杆的移动，屏幕上的圆也跟随移动并放大圆内的照片，
最后在屏幕上显示圆内放大照片的部分。

8、裁纸刀
	选择相应的图片进入操作砧板，手移动砧板图片，IMAGE图片跟着移动，
裁纸刀落下，IMAGE栏显示被裁剪后的图片。
	最后在大屏幕报纸上的文字下方显示编辑好的图片。


------------------------------------------------------

D、LAYOUT

9、方向盘
	方向盘左转一下：
		LAYOUT(标题、文本（多个）、标签、图片)，向左滚动一个内容。

	方向盘右转一下：
		LAYOUT(标题、文本（多个）、标签、图片)，向右滚动一个内容。

	方向盘不转：
		LAYOUT(标题、文本（多个）、标签、图片)，内容保持不变

	方向盘下方按钮（1-10）：
		按下对应的序号，对LAYOUT页中的内容进行缩放。数字逐渐变大，内容就逐渐缩小。
		在报纸页面按照数字（标序号）从前到后实时显示缩放后的内容。

10、喷灌
	选择合适的排版和色调，使用喷灌对报纸“上色”。
	根据不同的排版和色调组成不同的版面，可以通过拖拽改变版面上各内容的排布。
	喷灌拿起，大屏幕报纸所喷的位置逐渐显示最终排版。

11、滑动按钮
	调节画面饱和度/对比度/色温
	饱和度：增强/减弱
	对比度：增强/减弱
	色温：偏暖/偏冷
------------------------------------------------------
*/

/* 代码部分 */
#include <stdio.h>
#include <string.h>

/* 枚举 按键两种状态*/
typedef enum
{
	pressStatus,  //按下
	notPressStatus //未按下
}buttonStatus;


/* 枚举 吹风机的风向 */
typedef enum
{
	blowDown,	//吹风机向下吹
	blowUp,		//吹风机向上吹
	blowRight	//吹风机向右吹
}hairDryerDir;


/* 手指相关操作 */
typedef enum
{
	click,   //点击
	unselect, //取消选择
	magnify, //放大
	lessen   //缩小
}fingerOperation;


/* 操纵杆移动方向 */
typedef enum
{
	moveUp,    //向上移动
	moveDown,	//向下移动
	moveLeft,	//向左移动
	moveRight	//向右移动
}joystickDir;


/* 声明一个枚举类型，用来表示方向盘的状态 */
typedef enum
{
	steeringWheelCentre,    //0
	steeringWheelLeft,  	//1
	steeringWheelRight, 	//2
}steeringWheel;


/*--------------------------------------*/
/* 此部分的全局变量用于 HEADLIN */

/* HEADLIN标题行显示的内容 */
char headline[200] = {0};

/* 输入源，2种选择（键盘、喇叭） */
char SourceSelection[2] = {1,2};

/* 打气筒按压的次数 */
short numOfPresses = 0;

/* 标题膨胀的系数 */
short expansionFactor = 0;
/*--------------------------------------*/


/*--------------------------------------*/
/* 此部分的全局变量用于 TEXT */

/* 存放TEXT栏的内容 */
char textColumn[200] = {0};

/* 存放大屏幕报纸的内容 */
char bigScreenNewspaper[500] = {0};

//加粗 -> overstriking    灰色 -> grayness  高亮 -> hightlight
/* 用 指定的标记 在字符串中表示被高光笔划过的区域 */
char *tagsStart = "OGHL:";  //用于标记划到的开始区域（加粗+灰色高光）
char *tagsEnd = ":OGHL";  //用于标记划到的结束区域（加粗+灰色高光）


/* 0 ~ 8 表示第一行可以切换的按钮内容。  9 ~ 17 表示第二行可以切换的按钮内容。*/
char *buttonAllLabel[18] = {"文本1","标签1","文本2","标签2","文本3","标签3",
							"文本4","标签4","文本5","标签5","文本6","标签6",
							"文本7","标签7","文本8","标签8","文本9","标签9",};

/* 存放按钮上方的文字信息，0 ~ 2 表示第一行按钮上方的信息。  3 ~ 5 表示第二行按钮上方的信息*/
char *sixButtonsContent[6] = {NULL};

/* 表示6个按钮按键 */
char sixButtons[6] = {1,2,3,4,5,6};

/* 表示左右两边的四个三角形按钮， 1、2表示第一行的左右两个三角形按钮，3、4表示第二行的左右两个三角形按钮 */
char fourTriangle[4] = {1, 2, 3, 4};

/* 存放按下按钮的文字信息。每按一个按钮就把该按钮上方的文字信息存放在这
	最多能存放20个按钮的文字信息，如果需要增加，可以将数组大小变大。
*/
char *savePressButtonText[20] = {NULL};

/* 存放右侧小屏幕的文字信息 */
char *rightSrceen = NULL;

/* 用于记录一共按下多少次按钮 */
static char selectionCount = 0;
/*--------------------------------------*/


/*--------------------------------------*/
/* 此部分的全局变量用于 IMAGE */

/* 存放 IMAGE栏 内容 */
char iMageColumn[5][20] = {0};

/* 存放被选择的图片 */
char *nowCheckedImage[20] = {NULL};

/* 每个元素表示 IMAGE栏每张图片的大小 */
char imageSize[5] = {1, 1, 1, 1, 1};

/* 当识别按钮按下时，存放圆中被放大的图片部分 */
char *magnifyArea = "圆中放大部分";

/* 操纵杆移动的最后方向标记 */
char saveImageLastPos = 0;

/* IMAGE 裁剪后图片的数量 */
static int imageCount = 0;
/*--------------------------------------*/


/*--------------------------------------*/
/* 此部分得全局变量用于 LAYOUT */

/* 方向盘下方的按钮，用数组来表示10个按钮 */
char buttonNum[10] = {1,2,3,4,5,6,7,8,9,10};
/* 按钮的缩放系数 */
char buttonScaleFactor[10] = {20, 18, 16, 14, 12, 10, 8, 6, 4, 2};

/* LAYOUT页面上的标题 */
char *headlineP = headline;

/* LAYOUT页面上的文本以及标签 */
char **textAndLabel = savePressButtonText;

/* LAYOUT页面上的图片 */
char **picture = nowCheckedImage;

/* LAYOUT页面容器，分别存放标题、文本、标签、图片 */
char **LAYOUTContainer[3] = {NULL};

/* 用于显示LAYOUT页面当前的内容 */
char *LAYOUTMainDisplay = NULL;   //设置 LAYOUT界面 最开始显示的内容

/* 初始化LAYOUT页面所有的内容的大小为1 */
int contentSize[50] = {0};

/* 色调有256中颜色，0-255每个数字代表的颜色各不相同 */
unsigned char colorSelection[256] = {0};

/* 排版模板有50种，0-49每个数字代表的模板样式各不相同 */
unsigned char templateSelection[50] = {0};

/* 色调和模板的不同搭配，得到一个最终版面 */
short finalTemplate = 0;

/* 滑动按钮调节后，最终版面的画面效果 */
short finalGraphic = 0;
/*--------------------------------------*/



/**
  * @brief  使用不同的道具
  * @param  propFunc：函数指针，具体的某个道具
  * 		arg : 回调函数的参数，某个道具的参数
  * @retval 无
  */
void useItems(void *(*propFunc)(void *), void *arg)
{
	propFunc(arg);
}


/**
  * @brief  LAYOUT 相关设置之后，在大屏幕报纸上显示的内容
  * @param  无
  * @retval 无
  */
static void displayNewspaper_LAYOUT(void)
{
	int m = 1;
	int n = 0;

	char **textAndLabelTemp = textAndLabel;
	char **pictureTemp = picture;

	for(int i = 0;i < 3;i++)
	{
		if(i == 0)   //标题
		{
			printf("%d、%s   缩放大小：%d\n",m,*LAYOUTContainer[i], contentSize[n]);
			n++;
			m++;
		}
		else if(i == 1)   //文本以及标签
		{
			while(*textAndLabelTemp != NULL)
			{
				printf("%d、%s   缩放大小：%d\n",m,*textAndLabelTemp, contentSize[n]);
				n++;
				m++;
				textAndLabelTemp++;
			}
		}
		else    //图片
		{
			while(*pictureTemp != NULL)
			{
				printf("%d、%s   缩放大小：%d\n",m, *pictureTemp, contentSize[n]);
				n++;
				m++;
				pictureTemp++;
			}				
		}
	}

	printf("排版为：%d\n",finalTemplate);
	printf("画面饱和度效果为：%d\n",finalGraphic);
}



/**
  * @brief  IMAGE 相关设置之后，在大屏幕报纸上显示的内容
  * @param  无
  * @retval 无
  */
static void displayNewspaper_IMAGE(void)
{
	printf("%s\n",nowCheckedImage[imageCount]);
}



/**
  * @brief  TEXT 相关设置之后，在大屏幕报纸上显示的内容
  * @param  无
  * @retval 无
  */
static void displayNewspaper_TEXT(void)
{
	selectionCount = 0;
	for(int i = 0;i < sizeof(savePressButtonText)/sizeof(savePressButtonText[0]);i++)
	{
		printf("%s\n",savePressButtonText[i]);
	}
}


/**
  * @brief HEADLIN 设置之后，在大屏幕报纸上显示相关的内容 
  * @param  无
  * @retval 无
  */
static void displayNewspaper_HEADLIN(void)
{
	printf("标题：%s  膨胀系数：%d\n",headline, expansionFactor);
}

/**
  * @brief HEADLIN 、 TEXT 、 IMAGE 、 LAYOUT四种设置之后，在大屏幕报纸上显示最终内容 
  * @param  无
  * @retval 无
  */
void entiretyDisplayNewspaper(void)
{
	printf("\n--------------------------------\n");
	printf("-----------大屏幕报纸-------------\n");
	displayNewspaper_LAYOUT();
	printf("---------------------------------\n");
}


/**
  * @brief  根据输入参数选择不同的输入源
  * @param  selection：选择输入源
  * @retval char：返回对输入源操作之后的结果
  */
char getInputSource(char selection)
{
	/*
		根据输入源选择不同，做不同的事情
	*/
	if(selection == 1)
		return 1;
	else
		return 2;
}

/**
  * @brief  将声音转换成文字
  * @param  voice：声音信号
  * @retval char *：转换后的文字
  */
char* voiceToText(char *voice)
{
	char *temp = NULL;
	/*
	经过某些特定设备将声音信号转换成文字
	*/

	temp = voice;

	return temp;
}

/**
  * @brief  显示 HEADLIN栏 内容
  * @param  text：显示的文字
  * @retval 无
  */
void headlineDisplay(char *text)
{
	strcpy(headline, text);
	printf("\n-----------------------------------\n");
	printf("--------HEADLIN栏---------\n");
	printf("标题：%s\n",headline);
	printf("标题膨胀系数为：%d\n",expansionFactor);
	printf("-------------------------------------\n");
}

/**
  * @brief  打印喇叭转换的文字
  * @param  arg : 喇叭转换的文字内容
  * @retval void *：根据需要可以返回任何类型指针
  */
void* trumpetPrint(void *arg)
{
	char *text = (char *)arg;
	
	printf("\n---------------------------------\n");
	printf("----------拿起喇叭---------\n");		
	printf("喇叭转换的文字：%s\n",text);
	printf("-----------------------------------\n");

	return "ok";
}

/**
  * @brief  按压打气筒
  * @param  count：按压打气筒的次数
  * @retval 无
  */
void pressThePump(short count)
{
	expansionFactor += count;
	numOfPresses += count;
}


/**
  * @brief  打印按压打气筒的次数
  * @param  arg : 打气筒按压次数
  * @retval void *：根据需要可以返回任何类型指针
  */
void* PumpPrint(void *arg)
{
	short count = *(short *)arg;
	
	printf("\n---------------------------------\n");
	printf("----------拿起打气筒---------\n");		
	printf("打气筒按压的次数：%d\n",count);
	printf("-----------------------------------\n");

	return "ok";
}


/**
  * @brief  在字符串指定的位置插入字符串
  * @param  dest：目标字符串
  * 		src : 要插入的字符串
  * 		pos ： 插入的位置
  * @retval 返回插入完的字符串的首地址
  */
char *myStrInsertStr(char *dest, char *src, int pos)
{
	if(dest == NULL)
	{
		printf("插入目标的字符串不能为NULL\n");
		return NULL;
	}

	char temp[50] = {0};
	char *destStart = dest;

	if(pos > 0)
	{
		while(pos--)
		{
			dest++;
		}
		strcpy(temp, dest);
	}
	else
	{
		strcpy(temp, dest);
	}

	while(*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	strcat(destStart, temp);
	return destStart;
}


/**
  * @brief  设置TEXT栏的文本信息
  * @param  text：需要设置的字符串
  * @retval 无
  */
void setTextColumnContent(char *text)
{
	strcpy(textColumn, text);
	strcpy(bigScreenNewspaper, text);
}

/**
  * @brief  操作高光笔在大屏幕报纸上划关键字
  * @param  tagsArea：模拟高光笔划的关键字
  * @retval 无
  */
void hightlightBrushOperate(char *tagsArea)
{
	char *temp = NULL;
	char *ret = strstr(bigScreenNewspaper, tagsArea);
	if(ret == NULL)
	{
		printf("%s 字符串未在 %s中\n",tagsArea, bigScreenNewspaper);
		return;
	}

	int startPos = ret - bigScreenNewspaper;
	int endPos = startPos + strlen(tagsArea) + strlen(tagsStart);

	temp = myStrInsertStr(bigScreenNewspaper, tagsStart, startPos);
	temp = myStrInsertStr(temp, tagsEnd, endPos);

	strcpy(bigScreenNewspaper,temp);
}

/**
  * @brief  显示文本栏的内容
  * @param  无
  * @retval 无
  */
void textDisplay(void)
{
	printf("\n------------------------------------\n");
	printf("----------------TEXT栏----------------\n");
	printf("内容：%s\n",textColumn);
	printf("------------------------------------\n");
}

/**
  * @brief  打印高光笔在大屏幕上划过的文字
  * @param  arg : 高光笔划过的关键字
  * @retval void *：根据需要可以返回任何类型指针
  */
void* hightlightBrushPrint(void *arg)
{
	char *text = (char *)arg;
	
	printf("\n---------------------------------\n");
	printf("----------拿起高光笔---------\n");		
	printf("高光笔划的区域为：%s\n",text);
	printf("大屏幕报纸的内容：%s\n", bigScreenNewspaper);
	printf("-----------------------------------\n");

	return "ok";
}

/**
  * @brief  获取大屏幕报纸上没有被高光的其他文字
  * @param  str : 大屏幕报纸的内容
  * @retval char *：返回未被高光笔划过的文字
  */
static char *getNotHightlightString(char *str)
{	
	static char hightlightStr[100] = {0};
	char beforeDelete[100] = {0};
	char afterDelete[100] = {0};

	char *start = strstr(str, tagsStart);
	if(start == NULL)
	{
		printf("未找到高光笔划过的区域\n");
		return str;
	}
	
	char *end = strstr(str, tagsEnd);
	if(end == NULL)
	{
		printf("未找到高光笔划过的区域\n");
		return str;
	}

	int hightlightStrLen = end - start + 5;
	strncpy(beforeDelete, str, start-str);
	strncpy(afterDelete, end+5, strlen(str)-hightlightStrLen);

	strcat(hightlightStr, beforeDelete);
	strcat(hightlightStr, afterDelete);

	return hightlightStr;
}

/**
  * @brief  按下吹风机按钮
  * @param  dir : 吹风机 风口方向
  * @retval 无
  */
static void pressHairDryer(hairDryerDir dir)
{
	if(dir == blowUp)
	{
		printf("大屏幕报纸中的文字未被高光笔划过的区域被 向上吹散 \n");
	}
	else if(dir == blowDown)
	{
		printf("大屏幕报纸中的文字未被高光笔划过的区域被 向下吹散 \n");
	}
	else
	{
		printf("大屏幕报纸中的文字未被高光笔划过的区域被 向右吹散 \n");
	}

	printf("吹散的文字内容有：%s\n",getNotHightlightString(bigScreenNewspaper));

}

/**
  * @brief  打印吹风机 风向状态 以及大屏幕中被吹散的文字
  * @param  arg : 吹风机 风口方向
  * @retval void *：根据需要可以返回任何类型指针
  */
void* hairDryerPrint(void *arg)
{
	hairDryerDir hairDir = *(hairDryerDir *)arg;
	
	printf("\n---------------------------------\n");
	printf("----------拿起吹风机---------\n");
	if(hairDir == blowUp)
		printf("吹风机的方向为：向上吹\n");
	else if(hairDir == blowDown)
		printf("吹风机的方向为：向下吹\n");
	else
		printf("吹风机的方向为：向右吹\n");
	pressHairDryer(hairDir);
	printf("-----------------------------------\n");

	return "ok";
}

/**
  * @brief  初始化6个按钮上方的文字信息
  * @param  无
  * @retval 无
  */
void sixButtonsInit(void)
{
	for(int i = 0;i < sizeof(sixButtonsContent)/sizeof(sixButtonsContent[0]);i++)
	{
		sixButtonsContent[i] = buttonAllLabel[(i/3)*9+i%3];
	}
}

/**
  * @brief  打印6个按钮上方的文字信息
  * @param  无
  * @retval 无
  */
void displaySixButtonContent(void)
{
	printf("6个按钮上方的文字信息：\n");
	for(int i = 0;i < sizeof(sixButtonsContent)/sizeof(sixButtonsContent[0]);i++)
	{
		printf("%s ",sixButtonsContent[i]);
		if(i == 2)
			printf("\n");
	}
	printf("\n-------------------------\n");
}


/**
  * @brief  选择6个按钮中的哪个按钮，1 ~ 6，将上方的文字信息存放到右侧小屏幕上
  * @param  buttonNum：按钮标号
  * @retval 无
  */
void selectionButton(char buttonNum)
{
	rightSrceen = sixButtonsContent[buttonNum];
	savePressButtonText[selectionCount] = sixButtonsContent[buttonNum];
	selectionCount++;
}

/**
  * @brief  选择左右三角形按钮，1 ~ 4，用于切换6个按钮上方的文字信息
  * @param  triangleNum：三角形按钮标号
  * @retval 无
  */
void selectionTriangleButton(char triangleNum)
{
	static char firstButton = 0;
	static char secondButton = 0;
	static char thirdButton = 0;
	static char fourthButton = 0;
	if(triangleNum == fourTriangle[0])  //第一排左边的三角形按钮
	{
		sixButtonsContent[0] = buttonAllLabel[(firstButton+0)%9];
		sixButtonsContent[1] = buttonAllLabel[(firstButton+1)%9];
		sixButtonsContent[2] = buttonAllLabel[(firstButton+2)%9];
		secondButton--;
		firstButton++;
	}
	else if(triangleNum == fourTriangle[1])  //第一排右边的三角形按钮
	{
		sixButtonsContent[0] = buttonAllLabel[(8-secondButton+0)%9];
		sixButtonsContent[1] = buttonAllLabel[(8-secondButton+1)%9];
		sixButtonsContent[2] = buttonAllLabel[(8-secondButton+2)%9];
		firstButton--;
		secondButton++;
	}
	else if(triangleNum == fourTriangle[2])  //第二排左边的三角形按钮
	{
		sixButtonsContent[3] = buttonAllLabel[9+(thirdButton+0)%9];
		sixButtonsContent[4] = buttonAllLabel[9+(thirdButton+1)%9];
		sixButtonsContent[5] = buttonAllLabel[9+(thirdButton+2)%9];
		fourthButton--;
		thirdButton++;
	}
	else   //第二排右边的三角形按钮
	{
		sixButtonsContent[3] = buttonAllLabel[9+(8-fourthButton+0)%9];
		sixButtonsContent[4] = buttonAllLabel[9+(8-fourthButton+1)%9];
		sixButtonsContent[5] = buttonAllLabel[9+(8-fourthButton+2)%9];
		thirdButton--;
		fourthButton++;
	}
}

/**
  * @brief  打印按下哪个按钮，以及右侧屏幕的信息
  * @param  arg：按钮标号
  * @retval void *：根据需要可以返回任何类型指针
  */
void* sixButtonsPrint(void *arg)
{
	char pressNum = *(char *)arg;
	
	printf("\n---------------------------------\n");
	printf("----------按下六个按钮中的一个---------\n");		
	printf("按下的按钮为：%d\n",pressNum+1);
	printf("右侧小屏幕显示的信息：%s\n", rightSrceen);
	printf("-----------------------------------\n");

	return "ok";
}



/**
  * @brief  初始化IMAGE栏的内容，这里将IMAGE栏的5个内容设置
  * 			成 图片1、图片2、图片3、图片4、图片5
  * @param  无
  * @retval 无
  */
void iMageColumnInit(void)
{
	char str[10] = "图片";

	for(int i = 0;i < sizeof(iMageColumn)/sizeof(iMageColumn[0]);i++)
	{
		str[4] = '1'+i;
		strcpy(iMageColumn[i], str);
	}
}


/**
  * @brief  手指操作 IMAGE栏 的内容，可以用手指选择某张图片，
  * 			或者用手指对图片进行缩放，或者用手指取消对图片的选择
  * @param  image：需要选择的图片
  * 		imageLabel : 图片位于 IMAGE栏 的哪个位置
  * 		option：手指对图片的操作方式
  * 				有以下四种方式：	click、unselect、magnify、lessen
  * @retval char:返回被操作的图片在IMAGE栏中的位置
  */
char imageOperate(char *image, char imageLabel, fingerOperation option) 
{
	int i = 0;
	while(strcmp(image, iMageColumn[i]))
	{
		i++;
		if(i > (sizeof(iMageColumn)/sizeof(iMageColumn[0])))
		{
			printf("选择的 %s 照片未在IMAGE栏中，请重新选择\n",image);
			return -1;
		}
	}

	if(option == click)
	{
		nowCheckedImage[imageCount] = image;
		printf("点击照片，照片为：%s\n",image);
	}
	else if(option == magnify)
	{
		imageSize[imageLabel-1] += 1;
		printf("照片被放大，大小增加到%d\n",imageSize[imageLabel-1]);
	}
	else if(option == lessen)
	{
		if(imageSize[imageLabel-1] > 1)
		{
			imageSize[imageLabel-1] -= 1;
		}
		printf("照片被缩小，大小减小到%d\n",imageSize[imageLabel-1]);
	}
	else
	{
		printf("照片被取消选择，\n");
		nowCheckedImage[imageCount] = NULL;
	}

	return imageLabel;
}


/**
  * @brief  打印手指对图片的操作
  * @param  arg : 手指的操作方式
  * @retval void *：根据需要可以返回任何类型指针
  */
void* fingerPrint(void *arg)
{
	fingerOperation option = *(fingerOperation *)arg;
	
	printf("\n---------------------------------\n");
	printf("----------手指操作---------\n");
	if(option == click)
	{
		printf("手指点击图片\n");
	}
	else if(option == magnify)
	{
		printf("手指放大图片\n");
	}
	else if(option == lessen)
	{
		printf("手指缩小图片\n");
	}
	else if(option == unselect)
	{
		printf("手指取消选择，\n");
	}
	else
	{
		printf("手指未操作图片\n");
	}
	
	printf("-----------------------------------\n");

	return "ok";
}


/**
  * @brief  显示IMAGE栏的内容信息，
  * 			如果没有选中IMAGE栏的图片，该函数就用于显示IMAGE栏所有内容。
  * 			如果选中IAMGE栏中的其中一张照片，该函数就点亮(IAMGE中单独显示这张图片)被选中的照片。
  * @param  无
  * @retval 无
  */
void iMageColumnDisplay(void)
{
	printf("\n------------------------------------\n");
	printf("----------------IMAGE栏----------------\n");
	if(nowCheckedImage[imageCount] != NULL)
	{
		printf("%s\n", nowCheckedImage[imageCount]);
	}
	else
	{
		for(int i = 0;i < sizeof(iMageColumn)/sizeof(iMageColumn[0]);i++)
		{
			printf("%s  ",iMageColumn[i]);
		}
		printf("\n");
	}
	
	printf("------------------------------------\n");
}


/**
  * @brief  移动操纵杆
  * @param  moveDir：移动操纵杆的方式。
  * 					有三种方式：moveUp、moveDown、moveLeft、moveRight
  * @retval 无
  */
void moveJoystick(joystickDir moveDir)
{
	if(moveDir == moveUp)
	{
		printf("放大镜向上移动，并放大照片\n");
		saveImageLastPos = 1;
	}
	else if(moveDir == moveDown)
	{
		printf("放大镜向下移动，并放大照片\n");
		saveImageLastPos = 2;
	}
	else if(moveDir == moveLeft)
	{
		printf("放大镜向左移动，并放大照片\n");
		saveImageLastPos = 3;
	}
	else if(moveDir == moveRight)
	{
		printf("放大镜向右移动，并放大照片\n");
		saveImageLastPos = 4;
	}
	else
	{
		printf("放大镜不移动\n");
		saveImageLastPos = 5;
	}
}


/**
  * @brief  按下操纵杆的识别按钮
  * @param  无
  * @retval 无
  */
void pressEnsureButton(void)
{
	printf("\n操纵杆的按钮被按下，即将选择放大的照片\n");

	if(saveImageLastPos == 1)
	{
		magnifyArea = "放大镜向上移动后，圆中放大部分";
	}
	else if(saveImageLastPos == 2)
	{
		magnifyArea = "放大镜向下移动后，圆中放大部分";
	}
	else if(saveImageLastPos == 3)
	{
		magnifyArea = "放大镜向左移动后，圆中放大部分";
	}
	else if(saveImageLastPos == 4)
	{
		magnifyArea = "放大镜向右移动后，圆中放大部分";
	}
	else
	{
		printf("放大镜不移动\n");
	}
}

/**
  * @brief  打印操纵杆对图片的操作
  * @param  arg : 操纵杆的操作方式
  * @retval void *：根据需要可以返回任何类型指针
  */
void* joystickPrint(void *arg)
{
	joystickDir joyDir = *(joystickDir *)arg;
	
	printf("\n---------------------------------\n");
	printf("----------移动操纵杆---------\n");
	if(joyDir == moveUp)
		printf("操纵杆的方向：向上移动\n");
	else if(joyDir == moveDown)
		printf("操纵杆的方向：向下移动\n");
	else if(joyDir == moveLeft)
		printf("操纵杆的方向：向左移动\n");
	else if(joyDir == moveRight)
		printf("操纵杆的方向：向右移动\n");
	else
		printf("操纵杆的方向：未移动\n");
	
	printf("-----------------------------------\n");

	return "ok";
}


/**
  * @brief  裁纸刀的操作，对操作过的图片进行裁剪
  * @param  image : 需要裁剪的图片
  * 		clippedContent：需要裁剪掉的内容，这里就用一个字符串来表示
  * 		newStatus：是否使能裁剪功能
  * 			0：不进行裁剪操作
  * 			1：确定进行裁剪操作
  * @retval 无
  */
void sewingScissorsOperate(char *image, char *clippedContent, char newStatus)
{
	if(newStatus == 0)  /* 图片进入操作砧板进行移动，但是不对图片进行裁剪*/
	{
		printf("图片进入操作砧板\n");
		printf("图片跟随手移动\n");
		printf("未识别裁剪到落下，不做任何裁剪\n");
	}
	else if(newStatus == 1)  /* 图片进入操作砧板进行移动，但是对图片进行裁剪*/
	{
		printf("图片进入操作砧板\n");
		printf("图片跟随手移动\n");
		printf("移动之后，选择裁剪的部分为：%s\n", clippedContent);
		printf("识别到裁剪刀落下\n");
		nowCheckedImage[imageCount] = "裁剪过后的图片";
	}
	else
	{
		printf("输入的操作参数有误，未做任何改变");
	}
}


/**
  * @brief  打印裁纸刀裁剪的内容，以及裁剪后的图片
  * @param  arg : 裁剪的内容
  * @retval void *：根据需要可以返回任何类型指针
  */
void* sewingScissorsPrint(void *arg)
{
	char *content = (char *)arg;
	
	printf("\n---------------------------------\n");
	printf("----------裁纸刀---------\n");		
	printf("裁掉的部分内容为：%s\n",content);
	printf("裁剪剩下的内容为：%s\n",nowCheckedImage[imageCount]);
	printf("裁剪成功\n");
	printf("-----------------------------------\n");

	return "ok";
}



/**
  * @brief  初始化LAYOUT界面的内容
  * @param  无
  * @retval 无
  */
void LAYOUTContainerInit(void)
{
	for(int i = 0;i < sizeof(contentSize)/sizeof(contentSize[0]);i++)
	{
		contentSize[i] = 1;
	}

	LAYOUTContainer[0] = &headlineP;
	LAYOUTContainer[1] = textAndLabel;
	LAYOUTContainer[2] = picture;

	LAYOUTMainDisplay = *LAYOUTContainer[0];

	/* 显示初始化之后的内容 */
	#if 0
	for(int i = 0;i < 4;i++)
	{
		if(i == 0 || i == 2)
			printf("LAYOUTContainer[%d] = %s\n",i,*LAYOUTContainer[i]);
		else if(i == 1 || i == 3)
		{
			for(int j = 0;j < 3;j++)
			{
				if(i == 3)
					printf("picture[%d] = %s\n",j,picture[j]);
				else
					printf("text[%d] = %s\n",j,text[j]);
			}
		}
	}
	printf("LAYOUT界面初始化之后显示的内容：%s\n",LAYOUTMainDisplay);
	printf("---------------------------------\n");
	#endif
}

/**
  * @brief  方向盘右转操作函数，右转一下，LAYOUTMainDisplay 就显示右边的内容
  * @param  无
  * @retval 无
  */
void steeringWheelRightOperate(void)
{
	static int textCount = 0;
	static int pictureCount = 0;
	static int rightCount = 1;

	printf("方向盘向右转动第%d次\n",rightCount);

	if(LAYOUTMainDisplay == *LAYOUTContainer[0])  //标题
	{
		LAYOUTMainDisplay = LAYOUTContainer[1][textCount];  //显示文本1
		textCount++;
	}
	else if(LAYOUTMainDisplay == LAYOUTContainer[1][textCount-1])  //文本
	{
		if(textAndLabel[textCount] == NULL)   //文本标签遍历完了之后，就遍历图片
		{
			LAYOUTMainDisplay = *LAYOUTContainer[2];
			textCount = 0;
		}
		else
		{
			LAYOUTMainDisplay = LAYOUTContainer[1][textCount];
			textCount++;
		}

	}
	else  //图片
	{
		if(picture[pictureCount] == NULL)
		{
			LAYOUTMainDisplay = *LAYOUTContainer[0];
			pictureCount = 0;
		}
		else
		{
			LAYOUTMainDisplay = LAYOUTContainer[2][pictureCount];
			pictureCount++;
		}
	}

	rightCount++;
}

/**
  * @brief  方向盘左转操作函数，右转一下，LAYOUTMainDisplay 就显示左边的内容
  * @param  无
  * @retval 无
  */
void steeringWheelLeftOperate(void)
{
	static int textCount = sizeof(savePressButtonText)/sizeof(savePressButtonText[0]);
	static int pictureCount = sizeof(nowCheckedImage)/sizeof(nowCheckedImage[0]);
	static int leftCount = 1;

	printf("方向盘向左转动第%d次\n",leftCount);

	if(LAYOUTMainDisplay == *LAYOUTContainer[0])  //标题
	{
		LAYOUTMainDisplay = LAYOUTContainer[3][pictureCount-1];  //显示最后一张图片
		pictureCount--;
	}
	else if(LAYOUTMainDisplay == LAYOUTContainer[1][textCount])  //文本
	{
		if(textCount == 0)
		{
			LAYOUTMainDisplay = *LAYOUTContainer[0];
			textCount = sizeof(savePressButtonText)/sizeof(savePressButtonText[0]);
		}
		else
		{
			LAYOUTMainDisplay = LAYOUTContainer[1][textCount-1];
			textCount--;
		}
	}
	else if(LAYOUTMainDisplay == *LAYOUTContainer[2])  //标签
	{
		LAYOUTMainDisplay = LAYOUTContainer[1][textCount-1];  //显示最后一个文本
		textCount--;
	}
	else  //图片
	{

		if(pictureCount == 0)
		{
			LAYOUTMainDisplay = *LAYOUTContainer[2];
			pictureCount = sizeof(nowCheckedImage)/sizeof(nowCheckedImage[0]);
		}
		else
		{
			LAYOUTMainDisplay = LAYOUTContainer[3][pictureCount-1];
			pictureCount--;
		}
	}

	leftCount++;
}

/**
  * @brief  方向盘不转动操作函数
  * @param  无
  * @retval 无
  */
void steeringWheelCentreOperate(void)
{
	/*
		由于方向盘不转动，根据需要做相应的事情。
	*/

}

/**
  * @brief  方向盘的操作方式选择
  * @param  sWheel：枚举类型，有三种选择，如下三种：
  * 						steeringWheelCentre： 方向盘不动
							steeringWheelLeft  ： 方向盘左转
							steeringWheelRight ： 方向盘右转
  * @retval 无
  */
void steeringWheelOperate(steeringWheel sWheel)
{
	switch(sWheel)
	{
		case 0:
			steeringWheelCentreOperate();
		break;
		case 1:
			steeringWheelLeftOperate();
		break;
		case 2:
			steeringWheelRightOperate();
		break; 
	}
}

/**
  * @brief  LAYOUT界面当前显示内容，内容大小通过 “缩放大小”字眼 来表示
  * @param  无
  * @retval 无
  */
void LAYOUTContainerDisplay(void)
{	
	int i = 0;
	int j = 0;
	if(LAYOUTMainDisplay == headlineP)
		printf("LAYOUT界面显示的内容：%s   缩放大小：%d\n",LAYOUTMainDisplay,contentSize[0]);
	
	if(*textAndLabel != NULL)
	{
		while(textAndLabel[i] != NULL)
		{
			if(LAYOUTMainDisplay == textAndLabel[i])
			{
				printf("LAYOUT界面显示的内容：%s   缩放大小：%d\n",LAYOUTMainDisplay,contentSize[1+i]);
				break;
			}
			i++;
		}
	}

	if(*picture != NULL)
	{
		while(picture[j] != NULL)
		{
			if(LAYOUTMainDisplay == picture[j])
			{
				printf("LAYOUT界面显示的内容：%s   缩放大小：%d\n",LAYOUTMainDisplay,contentSize[1+i+j]);
				break;
			}
			j++;
		}
	}

	printf("---------------------------------\n");
}

/**
  * @brief  设置LAYOUT界面当前内容的缩放大小。
  * @param  ScaleFactor：每个按钮对应的缩放系数
  * @retval 无
  */
void contentScaleFactorOperate(char ScaleFactor)
{
	int i = 0;
	int j = 0;

	if(LAYOUTMainDisplay == headlineP)
		contentSize[0] *= ScaleFactor; 
	
	if(*textAndLabel != NULL)
	{
		while(textAndLabel[i] != NULL)
		{
			if(LAYOUTMainDisplay == textAndLabel[i])
			{
				contentSize[1+i] *= ScaleFactor;
				break;
			}
			i++;
		}
	}

	if(*picture != NULL)
	{
		while(picture[j] != NULL)
		{
			if(LAYOUTMainDisplay == picture[j])
			{
				contentSize[1+i+j] *= ScaleFactor;
				break;
			}
			j++;
		}
	}
}

/**
  * @brief  按钮操作，按下标号按钮
  * @param  num：按钮标号
  * @retval 无
  */
void buttonOperate(char num)
{
	switch(num)
	{
		case 1:
			contentScaleFactorOperate(buttonScaleFactor[0]);
		break;
		case 2:
			contentScaleFactorOperate(buttonScaleFactor[1]);
		break;
		case 3:
			contentScaleFactorOperate(buttonScaleFactor[2]);
		break;
		case 4:
			contentScaleFactorOperate(buttonScaleFactor[3]);
		break;
		case 5:
			contentScaleFactorOperate(buttonScaleFactor[4]);
		break;
		case 6:
			contentScaleFactorOperate(buttonScaleFactor[5]);
		break;
		case 7:
			contentScaleFactorOperate(buttonScaleFactor[6]);
		break;
		case 8:
			contentScaleFactorOperate(buttonScaleFactor[7]);
		break;
		case 9:
			contentScaleFactorOperate(buttonScaleFactor[8]);
		break;
		case 10:
			contentScaleFactorOperate(buttonScaleFactor[9]);
		break;
	}
}

/**
  * @brief  打印按下按钮的标号
  * @param  arg：按钮标号
  * @retval void *：根据需要可以返回任何类型指针
  */
void* buttonPrint(void *arg)
{
	char num = *(char *)arg;

	printf("\n-----------------------------------\n");
	printf("-----方向盘下方按钮---------\n");
	printf("------按下的按钮为：%d------\n",num);
	printf("-----------------------------------\n");

	return "ok";
}


/**
  * @brief  打印方向盘的状态，三种(未转动、向左转动、向右转动)
  * @param  arg：方向盘的状态
  * @retval void *：根据需要可以返回任何类型指针
  */
void* steeringWheelPrint(void *arg)
{
	steeringWheel *sWheelEnum = (steeringWheel *)arg;

	printf("\n--------------------------------\n");
	printf("-----------方向盘转动------------\n");

	if(*sWheelEnum == steeringWheelCentre)
		printf("---------方向盘未转动------------\n");
	else if(*sWheelEnum == steeringWheelLeft)
		printf("---------方向盘向左转动----------\n");
	else
		printf("---------方向盘向右转动----------\n");

	printf("-----------------------------------\n");

	return "ok";
}

/**
  * @brief  给色调容器(数组)和模板容器(数组)设置初始化值
  * @param  无
  * @retval 无
  */
static void colorAndTemplateInit(void)
{
	for(int i = 0;i < 256;i++)
	{
		colorSelection[i] = i;
		
		if(i < 50)
			templateSelection[i] = i;
	}
}

/**
  * @brief  获取LAYOUT界面的最终版面样式
  * @param  color：色调（0 ~ 255）
  * 				template：模板（0 ~ 49）
  * @retval short：返回色调和模板组合后的最终版面
  */
short getFinalLayout(short color, short template)
{
	short finalLayout = 0;

	if((color > 255) || (template > 50))
	{
		return -1;
	}

	colorAndTemplateInit();

	finalLayout = colorSelection[color] * templateSelection[template];

	return finalLayout;
}

/**
  * @brief  打印喷灌选择的色调和模板
  * @param  arg：色调和模板
  * @retval void *：根据需要可以返回任何类型指针
  */
void* sprayIrrigationPrint(void *arg)
{
	short *finalLayout = (short *)arg;
	
	printf("\n---------------------------------\n");
	printf("----------拿起喷灌---------\n");		
	printf("排版模板为：%d  排版色调为：%d\n", finalLayout[0], finalLayout[1]);
	printf("喷灌之后，排版为：%d\n",finalLayout[2]);
	printf("-----------------------------------\n");

	return "ok";
}

/**
  * @brief  设置画面效果(画面饱和度/对比度/色温)
  * @param  saturabilityArg：饱和度（-128 ~ 127）
  * 				contrastRatioArg：对比度（-128 ~ 127）
  * 				colorTempArg：色温（-128 ~ 127）
  * @retval int：返回最终画面效果
  */
int setGraphicEffect(short saturabilityArg, short contrastRatioArg, short colorTempArg)
{
	int getGraphic = 0;
	if((saturabilityArg < -128 && saturabilityArg > 127) || 
		(contrastRatioArg < -128 && contrastRatioArg > 127) ||
		(colorTempArg < -128 && colorTempArg > 127))
	{
		return -1;
	}

	getGraphic = saturabilityArg * contrastRatioArg * colorTempArg;

	return getGraphic;
}

/**
  * @brief  打印滑动按钮设置的画面饱和度/对比度/色温
  * @param  arg：画面饱和度/对比度/色温
  * @retval void *：根据需要可以返回任何类型指针
  */
void* slidingButtonsPrint(void *arg)
{
	short *finalLayout = (short *)arg;

	printf("\n-----------------------------------\n");
	printf("---------滑动 滑动按钮----------\n");	
	printf("画面饱和度为：%d  对比度为：%d  色温为：%d\n",finalLayout[0], finalLayout[1], finalLayout[2]);
	printf("滑动按钮之后，画面效果为：%d\n",finalLayout[3]);
	printf("-----------------------------------\n");

	return "ok";
}



int main()
{
	/* HEADLIN */
	char *output = NULL;
	char res = getInputSource(SourceSelection[0]);
	if(res == 1)
	{
		char *source = "trumpet input";
		output = voiceToText(source);
		useItems(trumpetPrint, output);
	}
	else
	{
		output = "keyboard input";
	}

	headlineDisplay(output);

	pressThePump(5);
	useItems(PumpPrint,&numOfPresses);
	headlineDisplay(output);


	/* TEXT */
	setTextColumnContent("abcdefghijklmnopqrstuvwxyz");
	textDisplay();
	hightlightBrushOperate("abcdef");
	useItems(hightlightBrushPrint, "abcdef");

	hairDryerDir hairDir = blowDown;
	useItems(hairDryerPrint, &hairDir);

	sixButtonsInit();
	displaySixButtonContent();
	selectionButton(sixButtons[1]);
	useItems(sixButtonsPrint,&sixButtons[1]);
	selectionButton(sixButtons[2]);
	useItems(sixButtonsPrint,&sixButtons[2]);

	
	/* IMAGE */
	char *image = iMageColumn[0];
	fingerOperation fo = click;
	joystickDir joyDir = moveUp;

	iMageColumnInit();
	iMageColumnDisplay();

	imageOperate(image, 1, fo);
	useItems(joystickPrint, &joyDir);	
	moveJoystick(joyDir);
	pressEnsureButton();
	iMageColumnDisplay();

	sewingScissorsOperate(image, "xxxxxx", 1);
	useItems(sewingScissorsPrint, "xxxxxx");
	iMageColumnDisplay();


	/* LAYOUT */
	LAYOUTContainerInit();
	steeringWheel sWheelEnum = steeringWheelLeft;
	steeringWheelOperate(sWheelEnum);
	LAYOUTContainerDisplay();
	useItems(steeringWheelPrint,&sWheelEnum);

	sWheelEnum = steeringWheelRight;
	steeringWheelOperate(sWheelEnum);
	LAYOUTContainerDisplay();
	useItems(steeringWheelPrint,&sWheelEnum);

	buttonOperate(buttonNum[0]);
	useItems(buttonPrint,&buttonNum[0]);
	
	short templateArg[3] = {20, 30, 0};
	finalTemplate = getFinalLayout(templateArg[0], templateArg[1]);
	if(finalTemplate < 0)
	{
		printf("输入色调和模板参数超出范围\n");
		return -1;
	}
	templateArg[2] = finalTemplate;
	useItems(sprayIrrigationPrint,templateArg);
	
	short graphicArg[4] = {10, 20, 30, 0};
	finalGraphic = setGraphicEffect(graphicArg[0], graphicArg[1], graphicArg[2]);
	if(finalGraphic < 0)
	{
		printf("输入饱和度/对比度/色温参数超出范围\n");
		return -1;
	}
	graphicArg[3] = finalGraphic;
	useItems(slidingButtonsPrint,graphicArg);

	entiretyDisplayNewspaper();

	return 0;
}

