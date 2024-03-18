//  04_公务员面试
//
//描述：公务员面试现场打分。有7位考官，从键盘输入若干组成绩，每组7个分数（百分制），去掉一个最高分和一个最低分，输出每组的平均成绩。
//（注：本题有多组输入）
//输入描述：每一行，输入7个整数（0~100），代表7个成绩，用空格分隔。
//输出描述：每一行，输出去掉最高分和最低分的平均成绩，小数点后保留2位，每行输出后换行。
//输入：99 45 78 67 72 88 60
//输出：73.00


#include <stdio.h>

//方法一
//float averageScore(int *score, int len)
//{
//    int i = 0;
//    int max = score[0];
//    int min = score[0];
//    int maxFlag = 0;
//    int minFlag = 0;
//    float sum = 0;
//
//    for(i=0;i<len;i++)
//    {
//        if(score[i] > max)
//        {
//            max = score[i];
//        }
//        if(score[i] < min)
//        {
//            min = score[i];
//        }
//    }
//
//    for(i=0;i<len;i++)
//    {
//        if(score[i] == max && maxFlag == 0)
//        {
//            maxFlag = 1;
//            continue;
//        }
//        if(score[i] == min && minFlag == 0)
//        {
//            minFlag = 1;
//            continue;
//        }
//        sum += score[i];
//    }
//    return sum / (len-2);
//
//
//    //方法二
//    //使用排序的方法，先将他们升序排序，然后处理的时候就去掉第一个元素和最后一个元素。最后将其他元素加起来求平均
//}
//
//int main(int argc, const char * argv[])
//{
//    int score[7] = {0};
//    int len = sizeof(score)/sizeof(score[0]);
//    int i = 0;
//
//    while(scanf("%d",score+i) == 1)
//    {
//        i++;
//        if(i == 7)
//        {
//            float ret = averageScore(score,len);
//            printf("%.2f\n",ret);
//            i = 1;
//        }
//
//    }
//    return 0;
//}

//方法二
int main()
{
    int min = 100;
    int max = 0;
    int score = 0;
    int sum = 0;
    int i = 0;
    while(scanf("%d",&score) == 1)
    {
        i++;
        if(score > max)
            max = score;
        if(score < min)
            min = score;
        sum += score;
        
        if(i == 7)
        {
            printf("%.2f\n",(sum-max-min)/5.0);
            max = 0;
            min = 100;
            sum = 0;
            i = 0;
        }
        
    }
    
    return 0;
}

