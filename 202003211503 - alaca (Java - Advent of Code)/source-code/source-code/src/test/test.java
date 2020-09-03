package test;

import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

public class test {

	@Test
	public void Day1_test_method() {
		int[] values = {1,-1,4,3,6,-5,2,1,8,10,};
		try {

			int total = 0;

			System.out.println("Processing");
			

			for(int i = 0; i<10; i++) {
				total += values[i];
				System.out.println(i + ":\t" + values[i] + "\t->\t" + total);
			}
			System.out.println();
			System.out.println("Result: " + total);
		}
		catch(Exception error) {
			System.out.println(error);
		}
		System.out.println();
		System.out.println();
		
		try {
			List<Integer> allResults = new ArrayList<Integer>();

			int total = 0;
			System.out.println("Processing");
			while (true) 
			{
			

				for(int i = 0; i<10; i++) {

					total += values[i];
					if (allResults.contains(total)) 
					{
						System.out.println();
						System.out.println("Result: " + total);
						System.exit(0);
					}
					allResults.add(total);
					System.out.println(i + ":\t" + values[i] + "\t->\t" + total);
				}
			}
		} 
		catch (Exception error)
		{
			System.out.println(error);
		} 
		
	}
}
