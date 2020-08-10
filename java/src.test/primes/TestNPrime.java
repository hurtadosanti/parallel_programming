package primes;

import org.junit.Test;

import co.at3.primenumbers.proccessing.NPrime;

public class TestNPrime {
	@Test
	public void count() {
		NPrime p = new NPrime(10001);
		System.out.println(p.calculate());
	}
}
