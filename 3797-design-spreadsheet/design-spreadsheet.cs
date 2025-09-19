public class Spreadsheet {
    int[,] sheet;
    public Spreadsheet(int rows) {
        sheet = new int[rows,26];
    }
    
    public void SetCell(string cell, int value) {
        var (row, column) = getCellCoords(cell);
        sheet[row, column] = value;
    }
    
    public void ResetCell(string cell) {
        var (row, column) = getCellCoords(cell);
        sheet[row, column] = 0;
    }
    
    public int GetValue(string formula) {
        var plusIndex = formula.IndexOf('+');
		var firstPart = formula.Substring(1, plusIndex-1); //"=A1+6"
		var secondPart = formula.Substring(plusIndex+1);
		
		int firstNum = 0, secondNum = 0;
		if (firstPart[0] >= 'A' && firstPart[0] <= 'Z') {
			var (row, column) = getCellCoords(firstPart);
			firstNum = sheet[row, column];
		}
		else {
			firstNum = int.Parse(firstPart);
		}

		if (secondPart[0] >= 'A' && secondPart[0] <= 'Z') {
			var (row, column) = getCellCoords(secondPart);
			secondNum = sheet[row, column];
		}
		else {
			secondNum = int.Parse(secondPart);
		}
		
		return firstNum+secondNum;
    }

    private (int row, int column) getCellCoords(string cell) {
        int column = cell[0] - 'A';
        int row = int.Parse(cell.Substring(1)) - 1;

        return (row, column);
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.SetCell(cell,value);
 * obj.ResetCell(cell);
 * int param_3 = obj.GetValue(formula);
 */