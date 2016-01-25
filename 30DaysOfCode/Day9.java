import java.util.*;
class Solution {
	public static void main(String[] args) {
		int x, y;  
		Scanner sc = new Scanner(System.in);
		x = sc.nextInt(); 
		y = sc.nextInt();
		System.out.println(Solution.gcd(x, y));
	}
	public static int gcd(int x, int y) {
		return y == 0?x: gcd(y, x % y);  
	}
}
