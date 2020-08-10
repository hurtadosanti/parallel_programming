package co.at3.primenumbers.proccessing;

public class Util {

	public static boolean isPrime(Integer val) {
		if (val == 2 || val == 3) {
			return true;
		} else if (val % 2 == 0) {
			return false;
		} else {
			Double limit = Math.sqrt(val.doubleValue());
			for (int i = limit.intValue(); i > 1; i--) {
				if (val % i == 0) {
					return false;
				}
			}
			return true;
		}
	}

}
