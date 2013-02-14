package history;

import java.util.ArrayList;
import java.util.List;

import field.Field;

public class History {
	private List<Field> hist;

	public History() { hist = new ArrayList<Field>(); }
	
	public void addToHistory(Field next) {
		hist.add(next);
	}
	public Field takeFromHistory() {
		return hist.remove(hist.size()-1);
	}
	public void cleanHistory() {
		hist.clear();
	}
	public boolean notEmpty() {
		if (hist.isEmpty())
			return false;
		return true;
	}
}
