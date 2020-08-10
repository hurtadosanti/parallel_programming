package co.at3.primenumbers.proccessing;

public class NPrime {

	private Integer nNumber;

	public NPrime(Integer val) {
		this.nNumber = val;
	}

	public Integer calculate() {
		Integer count = 0;
		Integer num = 0;
		while (count <= nNumber) {
			num++;
			if (Util.isPrime(num)) {
				count++;
			}

		}
		return num;
	}

}
