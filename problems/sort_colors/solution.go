func sortColors(num []int)  {
    pivot := 1
	white := 0
	red := 0
	blue := len(num) - 1
	for white <= blue {
		switch {
		case num[white] < pivot:
			num[white], num[red] = num[red], num[white]
			white++
			red++
		case num[white] == pivot:
			white++
		default:
			num[blue], num[white] = num[white], num[blue]
			blue--
		}
	}
    
}