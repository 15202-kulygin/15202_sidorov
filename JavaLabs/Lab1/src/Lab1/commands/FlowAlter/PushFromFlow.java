package Lab1.commands.FlowAlter;

import java.util.Stack;
import Lab1.commands.Command;
import Lab1.ProgramProperties;
import Lab1.Flow;

public class PushFromFlow implements Command {
	public void execute( ProgramProperties prop ) {
		Stack<Integer> stack = prop.getStack();
		Flow flow = prop.getFlow();
		int y = stack.pop();
		int x = stack.pop();
		int value = flow.getSymbol(x,y);
		stack.push(value);
 	}
}