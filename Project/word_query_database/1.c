#include <stdio.h>

     #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <string.h>
int main()
{
        char data[100] = {0};
	char buff[] = "about";
        FILE* fp = fopen("./dict.txt","r");
        if(fp < 0)
        {
                perror("fopen fail");
                return -1;
        }
	int x = 0;
	int i = 0;
	while(fgets(data,100,fp) != NULL)
	{

		while( (data[i] != ' ') && (buff[x] != '\0') )
		{
				if(data[i] == buff[x])
				{
					x++;
				}
			i++;
		}
		if(x == strlen(buff))
		{
			while( *(data+x) == ' ' )
                        {
                                x++;
                        }

			printf("%s\n",data+x);
			break;
		}
		bzero(data,100);
		x = 0;
		i=0;
	}
	return 0;
}
