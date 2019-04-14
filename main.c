#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_NUMBERS 20

int main()
{
    const char alphabet[31] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
                         'z', '$', '*', '(', ')', '#'};

    while (1 == 1)
    {
        srand(time(NULL));
        unsigned int n, c;
        char  str;
        char mix[2];
        char pass[MAX_NUMBERS] = "";

        const unsigned int pass_size;

        printf("Please enter password size (max size: %d) or 'e' to exit: ", MAX_NUMBERS);
        scanf("%d", &pass_size);

        for (int i = 0; i < MAX_NUMBERS/2; i++)
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

        char return_pass[] = "";
        strncat(return_pass, pass, pass_size);

        char exit;
        scanf("%c", &exit);

        if (exit != '\n' && exit != 'e')
            continue;
        else if (exit == 'e')
            break;

        printf("Your random password: %s: \n\n",  return_pass);

    }

}
