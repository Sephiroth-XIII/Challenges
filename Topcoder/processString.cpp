/*
Problem Statement
    	
Class Name: StringProcessor
Method Name: processString
Parameters: String,String
Returns: String

Implement a class StringProcessor, which contains a method processString.  The
method takes two Strings as parameters: a String to process and a String of
commands.  The method successively (from left to right) processes the commands
in the command String on the String to process and returns the resulting String.

There is always a pointer pointing to some position in the String to process.
When the method starts, the pointer is pointing to the first character in the
String.  The pointer can point anywhere from the first character to 1 position
to the right of the last character.

The commands are:

0 - move pointer to point to first character. (That's a zero, not a capital
letter oh)

$ - move pointer to the position after the last character.

x - delete the character at the pointer position and shift all characters (if
any) after the position left.  The pointer location does not change.  This
command is processed only if the pointer position is not the position to the
right of the string.

s - swap the character at the pointer position with that to the right of it.
The pointer location does not change.  This command is processed as long as the
pointer is not at the last character or the position to the right of all
characters.

ic - shift all characters at and after the current position right and put the
character 'c' at the pointer location.  Then move the pointer location right so
it points to the same character it was pointing too before the insert (or
points to the right of the String if it pointed to the right of the String
before the insert).  'c' is a variable and can be any allowed character, even a
character that ordinarily is a command.

l - move the pointer right one position.  Processed if the current position is
not to the right of the string.

h - move the pointer left one position.  Processed if the current position is
not the first character.

u - undo the most recent processed command that is not undo, if there is such a
command.  Undo restores the String and pointer location to the state before the
last non-undo command was processed. Remember: Sometimes a command is given,
but not processed (because, for example, the end of the String has been
reached).  'x', 's', 'l', 'h' may be given but not processed.  '0', '$', 'ic'
are always processed when given.

The method signature is:
public String processString(String toProcess, String commands);

toProcess is a String containing letters('a'-'z', 'A'-'Z'), digits('0'-'9'),
spaces(' '), and punctuation ('.',',','?','!').  toProcess will have at least 1
character and at most 50 characters.
commands will be a String of valid commands only.  Any characters following an
'i' (insert) in the String will be letters, digits, spaces, or the punctuation
listed above.  commands will have at most 50 characters.
TopCoder will check that these Strings are valid.

Examples:
-if toProcess="It doesnt get any better than TopCoder." and
commands="lllluxxxxxxxxulllislllxhxi ilioit$hxhi!hs", the resulting String is:
"It gets a lot better than TopCoder!".  Note there is a space between the
second and third 'i' in the command string.

-if toProcess="This is a test." and commands = "0$$uhhhx", the resulting String
is "This is a tet."

-if toProcess="This is a test." and commands = "xhhhhhhhhhhhhhhhhhhhu", the
resulting String is "This is a test."
 
Definition
    	
Class:	StringProcessor
Method:	processString
Parameters:	String, String
Returns:	String
Method signature:	String processString(String param0, String param1)
(be sure your method is public)
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StringProcessor
{
	private:

		class Undo
		{
			public:
				string s;
				int p;

				Undo(string a, int b)
				{
					s = a;
					p = b;
				}
		};
	
	public:

		string processString(string toProcess, string commands)
		{
			int p = 0;

			vector<Undo> undo;

			for (int i = 0; i < commands.length() ; ++i)
			{
				switch(commands[i])
				{
					case '0':
					{
						undo.push_back(Undo(toProcess,p));
						p = 0;
						break;
					}
					case '$':
					{
						undo.push_back(Undo(toProcess,p));
						p = toProcess.size();
						break;
					}
					case 'x':
					{
						if(p < toProcess.size())
						{
							undo.push_back(Undo(toProcess,p));
							toProcess.erase(p,1);
						}
						break;
					}
					case 's':
					{
						if(p < toProcess.size() - 1)
						{
							undo.push_back(Undo(toProcess,p));
							swap(toProcess[p], toProcess[p+1]);
						}
						break;
					}
					case 'i':
					{
						undo.push_back(Undo(toProcess,p));
						toProcess.insert(p, 1, commands[i+1]);
						p++;
						i++;
						break;
					}
					case 'l':
					{
						if(p < toProcess.size())
						{
							undo.push_back(Undo(toProcess,p));
							p++;
						}
						break;
					}
					case 'h':
					{
						if(p > 0)
						{
							undo.push_back(Undo(toProcess,p));
							p--;
						}
						break;
					}
					case 'u':
					{
						int e = undo.size();
						if(e > 0)
						{
							undo.pop_back();
							toProcess = undo.end()->s;
							p = undo.end()->p;
						}
						break;
					}
					default:
						break;
				}
			}

			return toProcess;
		}
};

int main()
{
	StringProcessor *S = new StringProcessor;
	cout<<S->processString("ABCDEFG","xxulxiAlxxx")<<"\n";
	cout<<S->processString("undotest", "uuuxx0$0uuuu$hxuuuu")<<"\n";
	cout<<S->processString("we'll try some swapping", "llxllllllsiiiehhhx")<<"\n";
	cout<<S->processString("a1b2c3", "$hxhxu0iwx")<<"\n";
	cout<<S->processString("testingtesting", "iasllxxxuuuuu$$$uuuu")<<"\n";
	cout<<S->processString("a", "ibiciduu")<<"\n";
	cout<<S->processString("blah", "$iclu")<<"\n";
	cout<<S->processString("hello", "lllluuuiv")<<"\n";
	cout<<S->processString("tttttttt", "xxuu")<<"\n";
	cout<<S->processString("dsadas", "ix")<<"\n";
	cout<<S->processString("1234567", "iz$xhsuuu")<<"\n";
	cout<<S->processString("hello", "uuuuuu")<<"\n";
	cout<<S->processString("hello", "uuuuuuu")<<"\n";
	cout<<S->processString("Test", "ixixuu")<<"\n";
	cout<<S->processString("this is a test", "u")<<"\n";
	cout<<S->processString("Test", "ix0xhu")<<"\n";
	cout<<S->processString("123456789", "iz$xhsuuuihik0suux")<<"\n";
	cout<<S->processString("abc", "hhhhhhic")<<"\n";
	cout<<S->processString("a", "s")<<"\n";
	cout<<S->processString("abc", "lux")<<"\n";
	cout<<S->processString("test", "uxuxu")<<"\n";
	cout<<S->processString("aaaaaaaaaa", "xxxxuuuu")<<"\n";
	cout<<S->processString("tomtom", "$hx")<<"\n";
	cout<<S->processString("a", "ibiciduu")<<"\n";
	cout<<S->processString("aaa", "$ix")<<"\n";
	cout<<S->processString("abcdefgjiklk", "lllllluuix")<<"\n";
	cout<<S->processString("This is a test", "0$$uhhhx")<<"\n";
	cout<<S->processString("this is", "$$uu$$xxxsss0uuuiiihxxxxs$iiuu")<<"\n";
	cout<<S->processString("This is a test.", "xhhhhhhhhhhhhhu")<<"\n";
	cout<<S->processString("0lllllluuuuuuuuhhhisisis0llsllli!", "0lllllluuuuuuuuhhhisisis0llsllli!")<<"\n";
	cout<<S->processString("abc", "liuuif")<<"\n";
	cout<<S->processString("ttttttt", "xxuu")<<"\n";
	cout<<S->processString("test", "$hs")<<"\n";
	cout<<S->processString("This is a test from ned.", "llsllllsllllx")<<"\n";
	cout<<S->processString("This is a test", "su")<<"\n";
	cout<<S->processString("It doesnt get any better than TopCoder.", "lllluxxxxxxxxulllislllxhxi ilioit$hxhi!hs")<<"\n";
	cout<<S->processString("1", "icicicicicicicicicicicicicuuuuuuuuuuuuuuuuu")<<"\n";
	cout<<S->processString("abra cada . !dfad ", "llsllshsuic")<<"\n";
	cout<<S->processString("abcdefgh", "xxxxuu")<<"\n";
	cout<<S->processString("tomtom", "ipllik0uih")<<"\n";
	cout<<S->processString("It doesnt get any better than Topcoder.", "xxxxllllhhhxxxxi xx0lhl$$lxicigux")<<"\n";
	cout<<S->processString("Sorry Mike", "uuuuuuuu")<<"\n";
	cout<<S->processString("1", "icicicicicicuuuuuuuuuuuu")<<"\n";
	cout<<S->processString("this is a test", "llsikuu")<<"\n";
	cout<<S->processString("This is a test", "0$$uhhhx")<<"\n";
	cout<<S->processString("dsadasdsa", "uuu")<<"\n";


	return 0;
}