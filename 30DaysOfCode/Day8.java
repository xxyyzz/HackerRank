import java.util.*;
class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();	// Important
		HashMap<String, String> map = new HashMap<String, String>();
		String temp;
		while(n-- > 0) {
			temp = sc.nextLine();
			map.put(temp, sc.nextLine());
		}
		while(sc.hasNext()) {
			temp = sc.nextLine();
			if(map.containsKey(temp)) {
				System.out.println(temp+"="+map.get(temp));
			} else {
				System.out.println("Not found");
			}
		}
	}
}
