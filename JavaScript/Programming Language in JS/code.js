function InputStream(input) {
	var pos = 0, line = 1, col = 0;

	return {
		next : next, 
		peek : peek,
		eof : eof,
		croak : croak,
	};

	function next() {
		var ch = input.charAt(pos++);
		if (ch == "\n") line++, col = 0;
		else col++;

		return ch;
	}

	function peek() {
		return input.charAt(pos);
	}

	function eof() {
		return peek() == "";
	}

	function croak(msg) {
		throw new Error(msg + " (" + line + ":" + col + ") ");

	}
}

function read_next() {
	read_while(is_whitespace);

	if(input.eof()) return null;
	var ch = input.peek();

	if (ch == "#") {
		skip_comment();
		return read_next();
	}

	if (ch == '"') return read_string();

	if (is_digit(ch)) return read_number();

	if (is_id_start(ch)) return read_ident();

	if (is_punc(ch)) return {
		type : "punc",
		value : input.next()
	};

	if (is_op_char(ch)) return {
		type : "op", 
		value : read_while(is_op_char)
	};

	input.croak("Can't handle character: " + ch);

}

function TokenStream(input) {
	var current = null;
	var keywords = " if them else lambda λ true false ";

	return {
		next : next, 
		peek : peek,
		eof : eof,
		croak : input.croak
	};

	function is_keyword(x) {
		return keyword.indexOf(" " + x + " ") > = 0;
	}
	
	function is_digit(ch) {
		return /[0-9]/i.test.(ch);
	}	

	function is_id_start(ch) {
		return /[a-zλ_]/i.test(ch);
	}

	function is_id(ch) {
		return is_id_start(ch) || "?!-<>123456789".indexOf(ch) >= 0;
	}

	function is_op_char(ch) {
		return "+-*/%=&|<>!".indexOf(ch) >= 0;
	}

	
}