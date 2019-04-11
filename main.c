#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    const int max_numbers = 20;
    char alphabet[31] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
                         'z', '$', '*', '(', ')', '#'};

    while (1 == 1)
    {
        srand(time(NULL));
        unsigned int n, c;
        char  str;
        char mix[2];
        char pass[20] = "";

        for (int i = 0; i < max_numbers/2; i++)
        {
            n = rand() % 10;
            str = alphabet[rand() % 31];
            c = rand() % 2;

            if (c == 0)
                sprintf(mix, "%d%c", n, str);
            else
                sprintf(mix, "%c%d", str, n);

            strcat(pass, mix);
        }

        char exit;

        printf("Your random password: %s\n\nPress Enter to get another password\n"
                    "or Enter 'e' to quit\n",  pass);
        scanf("%c", &exit);

        if (exit != '\n' && exit != 'e')
            continue;
        else if (exit == 'e')
            break;
    }

}
