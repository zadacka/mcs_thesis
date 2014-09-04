def _ascii_read(data):
    # strip header (five lines)
    for i in range(5):
        data.readline()
    while True:
        l = data.readline()
        if not l:
            break
        # in our case, just parse the nine points correctly!
        yield [
            tuple( map(float, l.split()[0:3])),
            tuple( map(float, l.split()[3:6])), 
            tuple( map(float, l.split()[6:9]))]