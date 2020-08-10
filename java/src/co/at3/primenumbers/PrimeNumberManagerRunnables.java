package co.at3.primenumbers;

import co.at3.primenumbers.proccessing.SumOfPrimes;

public class PrimeNumberManagerRunnables {

	public static void main(String[] args) throws InterruptedException {
		SumOfPrimes s1 = new SumOfPrimes(2, 2000000);

		long start = System.currentTimeMillis();
		s1.calculate();
		long finish = System.currentTimeMillis();
		Long time = finish - start;
		System.out.println("Took:" + time);

		System.out.println("Result: " + s1.getResult());

	}

}
