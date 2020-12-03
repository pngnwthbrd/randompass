#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    const char alphabet[41] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                                'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u',
                                'v', 'w', 'x', 'y', 'z', '$', '*',
                                '(', ')', '#', '%', '!', '?', '&',
                                '-', '_', '[', ']', '{', '}'};

    while (1 == 1)
    {
        srand(time(NULL));
        unsigned int n, c;
        char  str;
        char mix[13];
        char *pass;

        unsigned int pass_size;

        printf("Please enter password size or 'e' to exit: ");
        scanf("%d", &pass_size);

        pass = (char *) malloc(pass_size * sizeof(char));

        if (pass == NULL) {
            printf("Not enough free memory to calculate the password :(!");
            return 0;
        }

        for (int i = 0; i <= pass_size/2; i++) {
            n = rand() % 10;
            str = alphabet[rand() % 41];
            c = rand() % 2;

            if (c == 0)
                sprintf(mix, "%d%c", n, str);
            else
                sprintf(mix, "%c%d", str, n);

            strcat(pass, mix);
        }

        char return_pass[] = "\0";
        strncat(return_pass, pass, pass_size);

        char exit;
        scanf("%c", &exit);

        if (exit != '\n' && exit != 'e')
            continue;
        else if (exit == 'e')
            break;

        printf("Your random password: %s \n\n",  return_pass);

        if (pass != NULL)
            free(pass);
    }
}
