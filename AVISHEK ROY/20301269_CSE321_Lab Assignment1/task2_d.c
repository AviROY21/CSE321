#include <stdio.h>
#include <string.h>

int main ()
{
  char email[50];
  char chr[20] = "sheba.xyz";
  printf ("Email: ");
  fgets (email, sizeof(email), stdin);
  email[strcspn(email, "\n")] = 0; 

  char *at_pos = strchr(email, '@');
  if (at_pos!= NULL)
    {
      char *result = strstr (at_pos, chr);
      if (result!= NULL)
        {
          printf ("Email address is okay.");
        }
      else
        {
          printf ("Email address is outdated");
        }
    }
  else
    {
      printf ("Invalid email address");
    }

  return 0;
}
