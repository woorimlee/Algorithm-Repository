int i = 1;
int sum = 0;
int num = 55;

while (sum < num) {
	sum += i;
	i++;
}

for (i = 1; sum < num; i++) {
	sum += i;
}

//i = 1 -> sum = 1
//i = 2 -> sum = 3
//...
// i = 9 -> sum = 45
// i = 10 -> sum = 55
// i = 11