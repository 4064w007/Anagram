//Written By: Christina Tkatchenko
//Project 4
//CS 211

#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv)
{

    if(argc<3)
    {
        printf("Correct number of arguments have not been provided");
        return 0;
    }
    char * subject =argv[1];
    char * anagram = argv[2];

    int charCount[26];
    int i;

    for(i=0;i<26;i++)
    {
        charCount[i]=0;
    }

    for(i=0;i<strlen(subject);i++)
    {
        int j = (int) subject[i];
        if(subject[i]!=' ')
        {
            charCount[j-97] = charCount[j-97] + 1;
        }
    }

    for(i=0;i<strlen(anagram);i++)
    {
        if(anagram[i]!=' ')
        {
            charCount[((int)anagram[i])-97] = charCount[((int)anagram[i])-97] - 1;
        }

    }

    int isAnagram=1;
    for(i=0;i<26;i++)
    {
        if(charCount[i]>0)
        {
            printf("The second argument is NOT an anagram because letter [%c] appears more times in subject when compared to 2nd argument\n",(97+i));
            isAnagram=0;
            break;
        }

        else if(charCount[i]<0)
        {
            printf("The second argument is NOT an anagram because letter [%c] appears less times in subject when compared to 2nd argument\n",(97+i));
            isAnagram=0;
            break;
        }
    }
    if(isAnagram==1)
    {
        printf("Second argument is actually an ANAGRAM of subject\n");
    }
    return 0;
}
