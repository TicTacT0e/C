#include <stdio.h>
#define LEN 5

void escape(char s[], char t[]);
void reescape(char t2[], char s[]);

int main()
{
	char t[LEN], s[LEN], t2[LEN];
	int c, i;

	i = 0;
	while ((c = getchar()) != EOF)
	{
		t[i] = c;
		i++;
	}
	t[i] = '\0';
	printf("\n");
	escape(s, t);
	reescape(t2, s);
	printf("%s", s);
	printf("\n\n");
	printf("%s", t2);
	printf("\n");
	return 0;
}

/*escape*/
void escape(char s[], char t[])
{
	int i, j;
	i = j = 0;

	while (t[i] != '\0')
	{
		switch (t[i])
		{
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			i++;
			break;
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			i++;
			break;
		default:
			s[j++] = t[i++];
			break;
		}
	}
	s[j] = '\0';
}

/*reescape*/
void reescape(char t2[], char s[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\\')
		{
			switch (s[++i])
			{
			case 'n':
				t2[j++] = '\n';
				i++;
				break;
			case 't':
				t2[j++] = '\t';
				i++;
				break;
			default:
				t2[j++] = s[i++];
				break;
			}
		}
		else
			t2[j++] = s[i++];
	}
	t2[j] = '\0';
}
