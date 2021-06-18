import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Day1_part1 {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Which input file: ");
		String fileLoc = scn.nextLine();
		try {

			int total = 0;

			System.out.println("Processing");

			BufferedReader br = new BufferedReader(new FileReader(fileLoc));
			String line;
			int lineNumber = 0;
			while ((line = br.readLine()) != null) {
				total += Integer.parseInt(line);
				lineNumber++;
				System.out.println(lineNumber + ":\t" + line + "\t->\t" + total);
			}
			System.out.println();
			System.out.println("Result: " + total);
			br.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}
