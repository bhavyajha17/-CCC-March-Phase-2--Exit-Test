def fourthBit(number):
    # Convert decimal number to binary
    binary = ""
    while number > 0:
        binary = str(number % 2) + binary
        number //= 2
    # Pad binary representation with leading zeros if necessary
    binary = binary.zfill(15)
    # Extract 4th digit from the right
    fourth_digit = binary[-4]
    # Convert fourth digit to integer and return it
    return int(fourth_digit)
