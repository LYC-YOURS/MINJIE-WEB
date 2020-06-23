
public class Fibonacci {

	public static long[] a = new long[1000];
	public static void main(String[] args) {
		for(int i = 1;i <= 200;i ++) {
			System.out.println(of(i));
		}
	}
	
	static {
		a[0] = 1;
		a[1] = 1;
	}

	public static long of(int i) {
		int key = 0;
		if(a[i - 1] == 0) {
			for(int j = i - 2; j >= 0; j --) {
				if(j != 0) {
					key = j;
					break;
				}
				
			}
			
			for(int j = key + 1; j < i ;j ++) {
				a[j] = a[j - 1] + a[j - 2];
				
				
			}
		}
		return a[i - 1];
		
	}
	
}
