//Bit stuffing

#include <stdio.h>

int main() {
	char str[100], ans[100];
	int i, n, count, j, k;
	char flag[] = "01111110";
	printf("Enter frame size: ");
	scanf("%d", &n);
	printf("Enter bit string: ");
	scanf("%s", str);
	
	i = 0;
    count = 1;
    j = 0;
    while (i < n) {
    	if (str[i] == '1') {
    		ans[j] = str[i];
    		for (k = i+1; str[k] == '1' && k < n && count < 5; k++) {
    			ans[++j] = str[k];
    			count++;
    			if (count == 5) {
    				ans[++j] = '0';
				}
				i = k;
			}
		} else {
			ans[j] = str[i];
		}
		i++;
		j++;
	}
	printf("After bit stuffing: ");
	printf("%s", flag);
	printf("%s", ans);
	printf("%s", flag);
	
	return 0;
}
	
    
