package co.at3.primenumbers.proccessing;

import java.math.BigInteger;

public class SumOfPrimes implements Runnable {

	private BigInteger result;
	private Integer low;
	private Integer max;

	public SumOfPrimes(Integer low, Integer max) {
		this.low = low;
		this.max = max;
		result = BigInteger.ZERO;
	}

	public BigInteger calculate() {
		for (Integer i = low; i < max; i++) {
			if (Util.isPrime(i)) {
				result = result.add(new BigInteger(i.toString()));
			}
		}
		return result;
	}

	public BigInteger getResult() {
		return result;
	}

	@Override
	public void run() {
		calculate();
	}
}
