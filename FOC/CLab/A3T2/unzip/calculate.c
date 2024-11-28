int calculate(int a, char c, int b){
	switch(c){
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
		case '%': return a%b;
	default:
		break;
	}
	return 0;
}
